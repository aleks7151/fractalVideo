# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vabraham <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/03 18:54:24 by vabraham          #+#    #+#              #
#    Updated: 2019/11/13 16:56:07 by vabraham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = src/main.c src/hook.c src/key_press.c src/color.c src/check_argv.c
LIB = includes/libft/libft.a
NAME = fractol
OBJ = $(patsubst %.c,%.o,$(FILES))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C includes/libft re
	@make -C minilibx_macos
	@gcc -L includes/libft -lft $(FILES) -I includes/libft -I src/fractal.h -o $(NAME) minilibx_macos/libmlx.a -framework OpenGL -framework AppKit
%.o: %.c
	@gcc -I src/fractal.h $< -c -o $@

clean:
	@rm -rf $(OBJ)
	@make -C includes/libft clean

fclean: clean
	@rm -rf $(NAME)
	@make -C includes/libft fclean

re: fclean all

.PHONY: all clean fclean re
