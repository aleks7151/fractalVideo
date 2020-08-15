/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabraham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 21:31:47 by vabraham          #+#    #+#             */
/*   Updated: 2019/11/02 21:31:47 by vabraham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H
# define WIDTH 900
# define HEIGHT 900
# define POT 60

# include <math.h>
# include "../minilibx_macos/mlx.h"
# include "../includes/libft/libft.h"
# include <pthread.h>

typedef struct		s_lstlst
{
	void			*mlx;
	void			*win;
	void			*img;
	int				n0;
	int				n1;
	int				n2;
	int				*data;
	int				ch_ar;
	int				pot;
	int				width;
	int				height;
	long double		w;
	long double		h;
	long double		sh_x;
	long double		sh_y;
	long double		tmp;
	long double		x_0;
	long double		y_0;
	float			c;
	float			v;
	int				cycle;
	int				str;
	int				movement;
	int				mouse_x;
	int				mouse_y;
	int				color;
	char			*fractal;
}					t_lst;

int					kp(int key, void *l);
int					mm(int x, int y, void *l);
int					mp(int b, int x, int y, void *l);
void				fon(t_lst *lst);
void				rain(t_lst *data);
int					close_my(void *lst);
void				fon(t_lst *lst);
void				error(void);
int					color(t_lst *lst, int i);
void				each0(t_lst *lst, long double *x,
						long double *y, long double tmp);
void				check_argv(int argc, char **argv, t_lst *lst, t_lst *lst0);
void				instruction(void);
void	*fractal(void *l);

#endif
