//  mlx_shaders.c

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <OpenGL/gl3.h>
#include "mlx_int.h"


void display_log(GLuint object, void (*param_func)(), void (*getlog_func)())
{
  GLint log_length;
  char *log;

  param_func(object, GL_INFO_LOG_LENGTH, &log_length);
  log = malloc(log_length);
  getlog_func(object, log_length, NULL, log);
  fprintf(stderr, "%s", log);
  free(log);
}


int mlx_shaders_pixel(glsl_info_t *glsl)
{
  char  *source;
  int	length;
  GLint action_ok;

  glsl->pixel_vshader = glCreateShader(GL_VERTEX_SHADER);
  source = strdup("#version 110 \n"
		  "attribute vec2 position;"
		  "varying vec2 texcoord;"
		  "void main()"
		  "{"
		  " gl_Position = vec4( position, 0.0, 1.0);"
		  " texcoord = vec2(position[0]+1.0, 1.0 - position[1]) / 2.0;"
		  "}");
  length = strlen(source);
  glShaderSource(glsl->pixel_vshader, 1, (const GLchar**)&source, &length);
  glCompileShader(glsl->pixel_vshader);
  free(source);

  glGetShaderiv(glsl->pixel_vshader, GL_COMPILE_STATUS, &action_ok);
  if (!action_ok) {
    fprintf(stderr, "Failed to compile pixel vshader :\n");
    display_log(glsl->pixel_vshader, glGetShaderiv, glGetShaderInfoLog);
    return (1);
  }

  glsl->pixel_fshader = glCreateShader(GL_FRAGMENT_SHADER);
  source = strdup("#version 110 \n"
		  "uniform sampler2D texture;"
		  "varying vec2 texcoord;"
		  "void main()"
		  "{"
		  " gl_FragColor = texture2D(texture, texcoord);"
		  "}");
  length = strlen(source);
  glShaderSource(glsl->pixel_fshader, 1, (const GLchar**)&source, &length);
  glCompileShader(glsl->pixel_fshader);
  free(source);

  glGetShaderiv(glsl->pixel_fshader, GL_COMPILE_STATUS, &action_ok);
  if (!action_ok) {
    fprintf(stderr, "Failed to compile pixel fshader :\n");
    display_log(glsl->pixel_fshader, glGetShaderiv, glGetShaderInfoLog);
    return (1);
  }

  glsl->pixel_program = glCreateProgram();
  glAttachShader(glsl->pixel_program, glsl->pixel_vshader);
  glAttachShader(glsl->pixel_program, glsl->pixel_fshader);
  glLinkProgram(glsl->pixel_program);

  glGetProgramiv(glsl->pixel_program, GL_LINK_STATUS, &action_ok);
  if (!action_ok) {
    fprintf(stderr, "Failed to link pixel shader program:\n");
    display_log(glsl->pixel_program, glGetProgramiv, glGetProgramInfoLog);
    return (1);
  }

  glFlush();

  return (0);
}


int mlx_shaders_image(glsl_info_t *glsl)
{
  char  *source;
  int	length;
  GLint action_ok;

  glsl->image_vshader = glCreateShader(GL_VERTEX_SHADER);
  source = strdup("#version 110 \n"
		  "attribute vec2 position;"
		  "uniform vec2 winhalfsize;"
		  "uniform vec2 imagepos;"
		  "uniform vec2 imagesize;"
		  "varying vec2 texcoord;"
		  "void main()"
		  "{"
		  " texcoord = position / imagesize;"
		  " vec2 pos = position - winhalfsize + imagepos;"
		  " pos = pos / winhalfsize;"
		  " gl_Position = vec4( pos, 0.0, 1.0);"
		  "}");
  length = strlen(source);
  glShaderSource(glsl->image_vshader, 1, (const GLchar**)&source, &length);
  glCompileShader(glsl->image_vshader);
  free(source);

  glGetShaderiv(glsl->image_vshader, GL_COMPILE_STATUS, &action_ok);
  if (!action_ok) {
    fprintf(stderr, "Failed to compile image vshader :\n");
    display_log(glsl->image_vshader, glGetShaderiv, glGetShaderInfoLog);
    return (1);
  }

  glsl->image_fshader = glCreateShader(GL_FRAGMENT_SHADER);
  source = strdup("#version 110 \n"
		  "uniform sampler2D texture;"
      "uniform float w;"
      "uniform float h;"
      "uniform float c;"
      "uniform float v;"
      "uniform int cycle;"
      "uniform int color;"
      "uniform float sh_x;"
      "uniform float sh_y;"
      "uniform int fractal;"
      "uniform float width;"
      "uniform float height;"
		  "varying vec2 texcoord;"


      "vec4 color_vec(int i, int col, int cyc){"
      " float red = 0.0, green = 0.0, blue = 0.0;"
      " float tmp = float(i) / float(cyc);"
      "float mn = 1.0;"
      " if (col == 0)"
	    " {"
		  "   red = 9.0 * (1.0 - tmp) * pow(tmp, 3.0) * mn;"
		  "   green = 15.0 * pow((1.0 - tmp), 2.0) * pow(tmp, 2.0) * mn;"
		  "   blue = 8.5 * pow((1.0 - tmp), 3.0) * tmp * mn;"
	    " }"
	    " else if (col == 1)"
	    " {"
		  "   red = 10.0 * (1.0 - tmp) * pow(tmp, 3.0) * mn;"
		  "   green = 0.0;"
		  "   blue = 8.0 * pow((1.0 - tmp), 3.0) * pow(tmp, 1.0) * mn;"
	    " }"
      " else if (col == 2)"
	    " {"
		  "   red = 0.0;"
		  "   green = 1.0 - 8.0 * pow((1.0 - tmp), 3.0) * pow(tmp, 1.0);"
		  "   blue = 1.0 - 10.0 * (1.0 - tmp) * pow(tmp, 3.0);"
	    " }"
	    " else if (col == 3)"
	    " {"
		  "   blue = 1.0 - 9.0 * (1.0 - tmp) * pow(tmp, 3.0);"
		  "   green = 1.0 - 15.0 *pow((1.0 - tmp), 2.0) * pow(tmp, 2.0);"
		  "   red = 8.5 * pow((1.0 - tmp), 3.0) * tmp;"
	    " }"
	    " else if (col == 4)"
	    " {"
		  "   blue = 15.0 * pow((1.0 - tmp), 2.0) * pow(tmp, 2.0);"
		  "   green = 15.0 * pow((1.0 - tmp), 2.0) * pow(tmp, 2.0);"
		  "   red = 9.0 * (1.0 - tmp) * pow(tmp, 3.0);"
	    " }"
      " else if (col == 5)"
	    " {"
		  "   blue = 1.0 - 15.0 * pow((1.0 - tmp), 2.0) * pow(tmp, 2.0);"
		  "   green = 0.0;"
		  "   red = 1.0 - 15.0 * pow((1.0 - tmp), 2.0) * pow(tmp, 2.0);"
	    " }"
	    " else if (col == 6)"
	    " {"
		  "   red = 9.0 * pow((1.0 - tmp), 1.0);"
		  "   green = 0.0;"
		  "   blue = 8.5 * pow((1.0 - tmp), 3.0);"
	    " }"
	    " else if (col == 7)"
	    " {"
      "   red = 0.0;"
		  "   blue = 9.0 * pow((1.0 - tmp), 1.0);"
		  "   green = blue / 2.0;"
	    " }"
	    " else if (col == 8)"
	    " {"
		  "   red = 9.0 * (1.0 - tmp) * pow(tmp, 3.0);"
		  "   green = 15.0 * pow((1.0 - tmp), 2.0) * pow(tmp, 2.0);"
		  "   blue = 1.0 - 8.5 * pow((1.0 - tmp), 3.0) * tmp;"
	    " }"
      " return vec4(red, green, blue, 0.0);"
      "}"


		  "void main()"
		  "{"
		  // " gl_FragColor = texture2D(texture, texcoord);"

      " float x = (texcoord.x * width - width / 2.0 + sh_x) / w / 2.0;"
      " float y = (texcoord.y * height - height / 2.0 + sh_y) / h / 2.0;"
      " float x_0 = x;"
      " float y_0 = y;"
      " float tmp = 0.0;"
      " int i = 0;"
      " while (i < cycle && x * x + y * y < 2.0 * 2.0){"
      "   if (fractal == 2)"
	    "   {"
		  "     tmp = x * x - y * y + x_0 + c;"
		  "     y = 2.0 * x * y + y_0 + v;"
		  "     x = tmp;"
	    "   }"
	    "   else if (fractal == 3)"
	    "   {"
		  "     tmp = x * x * x - 3.0 * x * y * y + c;"
		  "     y = 3.0 * x * x * y - y * y * y + v;"
		  "     x = tmp;"
	    "   }"
	    "   else if (fractal == 4)"
	    "   {"
		  "     tmp = x * x * x - 3.0 * x * y * y + x_0 + c;"
		  "     y = 3.0 * x * x * y - y * y * y + y_0 + v;"
		  "     x = tmp;"
	    "   }"
	    "   else if (fractal == 1)"
	    "   {"
		  "     tmp = x * x - y * y + c;"
		  "     y = 2.0 * x * y + v;"
		  "     x = tmp;"
	    "   }"
      "   i++;"
      " }"
	    " if (i == cycle)"
		  "   gl_FragColor = vec4(0.0, 0.0, 0.0, 0.0);"
      " else"
		  "   gl_FragColor = color_vec(i, color, cycle);"
		  "}");
  length = strlen(source);
  glShaderSource(glsl->image_fshader, 1, (const GLchar**)&source, &length);
  glCompileShader(glsl->image_fshader);
  free(source);

  glGetShaderiv(glsl->image_fshader, GL_COMPILE_STATUS, &action_ok);
  if (!action_ok) {
    fprintf(stderr, "Failed to compile image fshader :\n");
    display_log(glsl->image_fshader, glGetShaderiv, glGetShaderInfoLog);
    return (1);
  }

  glsl->image_program = glCreateProgram();
  glAttachShader(glsl->image_program, glsl->image_vshader);
  glAttachShader(glsl->image_program, glsl->image_fshader);
  glLinkProgram(glsl->image_program);

  glGetProgramiv(glsl->image_program, GL_LINK_STATUS, &action_ok);
  if (!action_ok) {
    fprintf(stderr, "Failed to link image shader program:\n");
    display_log(glsl->image_program, glGetProgramiv, glGetProgramInfoLog);
    return (1);
  }

  glFlush();

  return (0);
}




int mlx_shaders_font(glsl_info_t *glsl)
{
  char  *source;
  int	length;
  GLint action_ok;

  glsl->font_vshader = glCreateShader(GL_VERTEX_SHADER);
  source = strdup("#version 110 \n"
		  "attribute vec2 position;"
		  "uniform vec2 winhalfsize;"
		  "uniform vec2 fontposinwin;"
		  "uniform vec2 fontposinatlas;"
		  "uniform vec2 fontatlassize;"
		  "varying vec2 texcoord;"
		  "void main()"
		  "{"
		  " texcoord = (position * vec2(1.0, -1.0) + fontposinatlas ) / fontatlassize;"
		  " vec2 pos = position - winhalfsize + fontposinwin;"
		  " pos = pos / winhalfsize;"
		  " gl_Position = vec4( pos, 0.0, 1.0);"
		  "}");
  length = strlen(source);
  glShaderSource(glsl->font_vshader, 1, (const GLchar**)&source, &length);
  glCompileShader(glsl->font_vshader);
  free(source);

  glGetShaderiv(glsl->font_vshader, GL_COMPILE_STATUS, &action_ok);
  if (!action_ok) {
    fprintf(stderr, "Failed to compile font vshader :\n");
    display_log(glsl->font_vshader, glGetShaderiv, glGetShaderInfoLog);
    return (1);
  }

  glsl->font_fshader = glCreateShader(GL_FRAGMENT_SHADER);
  source = strdup("#version 110 \n"
		  "uniform sampler2D texture;"
		  "uniform vec4 color;"
		  "varying vec2 texcoord;"
		  "void main()"
		  "{"
		  " gl_FragColor = color * texture2D(texture, texcoord);"
		  "}");
  length = strlen(source);
  glShaderSource(glsl->font_fshader, 1, (const GLchar**)&source, &length);
  glCompileShader(glsl->font_fshader);
  free(source);

  glGetShaderiv(glsl->font_fshader, GL_COMPILE_STATUS, &action_ok);
  if (!action_ok) {
    fprintf(stderr, "Failed to compile font fshader :\n");
    display_log(glsl->font_fshader, glGetShaderiv, glGetShaderInfoLog);
    return (1);
  }

  glsl->font_program = glCreateProgram();
  glAttachShader(glsl->font_program, glsl->font_vshader);
  glAttachShader(glsl->font_program, glsl->font_fshader);
  glLinkProgram(glsl->font_program);

  glGetProgramiv(glsl->font_program, GL_LINK_STATUS, &action_ok);
  if (!action_ok) {
    fprintf(stderr, "Failed to link font shader program:\n");
    display_log(glsl->font_program, glGetProgramiv, glGetProgramInfoLog);
    return (1);
  }

  glFlush();

  return (0);
}



int mlx_shaders(glsl_info_t *glsl)
{
  return (mlx_shaders_pixel(glsl) + mlx_shaders_image(glsl) + mlx_shaders_font(glsl));
}
