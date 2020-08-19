/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabraham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 19:39:48 by vabraham          #+#    #+#             */
/*   Updated: 2019/11/01 19:39:50 by vabraham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//@gcc -Wall -Wextra -Werror -L includes/libft -lft $(FILES) -I includes/libft -I src/fractal.h -o $(NAME) -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
#include "fractal.h"

int		each(t_lst *lst, long double x, long double y)
{
	int			i;
	long double	r;

	r = 2;
	x = x / (lst->w / 2 / r);
	y = y / (lst->h / 2 / r);
	lst->x_0 = x;
	lst->y_0 = y;
	i = -1;
	while (++i < lst->cycle && x * x + y * y < r * r)
		each0(lst, &x, &y, 0);
	if (i == lst->cycle)
		return (0);
	return (color(lst, i));
}

// void	*fractal(void *l)
// {
// 	int		i;
// 	int		k;
// 	t_lst	*lst;

// 	lst = (t_lst*)l;
// 	k = -lst->height / 2 + lst->str * lst->height / lst->pot;
// 	while (k < -lst->height / 2 + (lst->str + 1) * lst->height / lst->pot)
// 	{
// 		i = -lst->width / 2;
// 		while (i < lst->width / 2)
// 		{
// 			lst->data[(k + lst->height / 2) * lst->width
// 				+ (i + lst->width / 2)] = each(lst,
// 				(long double)(i) + lst->sh_x, (long double)(k) + lst->sh_y);
// 			i += 1;
// 		}
// 		k += 1;
// 	}
// 	return (0);
// }

void	*fractal(void *l)
{
	int		i;
	int		k;
	t_lst	*lst;

	lst = (t_lst*)l;
	k = -lst->height / 2;
	while (k < lst->height / 2)
	{
		i = -lst->width / 2;
		while (i < lst->width / 2)
		{
			lst->data[(k + lst->height / 2) * lst->width
				+ (i + lst->width / 2)] = each(lst,
				(long double)(i) + lst->sh_x, (long double)(k) + lst->sh_y);
			i += 1;
		}
		k += 1;
	}
	return (0);
}

// void	rain(t_lst *data)
// {
// 	t_lst			lst[data->pot];
// 	pthread_t		threads[data->pot];
// 	pthread_attr_t	attr;
// 	int				rc;
// 	void			*status;

// 	pthread_attr_init(&attr);
// 	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
// 	data->str = -1;
// 	while (++(data->str) < data->pot)
// 	{
// 		ft_memcpy((void*)&lst[data->str], (void *)data, sizeof(t_lst));
// 		rc = pthread_create(&threads[data->str],
// 			NULL, fractal, (void *)(&lst[data->str]));
// 	}
// 	pthread_attr_destroy(&attr);
// 	data->str = -1;
// 	while (++(data->str) < data->pot)
// 		rc = pthread_join(threads[data->str], &status);
// }

void	window(t_lst *lst)
{
	lst->win = mlx_new_window(lst->mlx, lst->width, lst->height, "Fractal");
	lst->img = mlx_new_image(lst->mlx, lst->width, lst->height);
	mlx_hook(lst->win, 2, 0, kp, (void *)lst);
	mlx_hook(lst->win, 6, 0, mm, (void *)lst);
	mlx_hook(lst->win, 4, 0, mp, (void *)lst);
	mlx_hook(lst->win, 17, 0, close_my, (void *)0);
	lst->data = (int *)mlx_get_data_addr(lst->img,
		&(lst->n0), &(lst->n1), &(lst->n2));
	lst->color = 0;
	lst->sh_x = 0;
	lst->sh_y = 0;
	lst->c = 0;
	lst->v = 0;
	lst->cycle = 50;
	lst->movement = 0;
	// fractal((void *)lst);
	mlx_put_image_to_window(lst->mlx, lst->win, lst->img, 0, 0, lst->w, lst->h, lst->c, lst->v, lst->cycle, lst->color, lst->sh_x, lst->sh_y, lst->fractal[0], WIDTH, HEIGHT);
}

int		main(int argc, char **argv)
{
	t_lst	*lst;
	t_lst	*lst0;

	if (!(lst = malloc(sizeof(t_lst))))
		error();
	if (!(lst0 = malloc(sizeof(t_lst))))
		error();
	check_argv(argc, argv, lst, lst0);
	lst->mlx = mlx_init();
	window(lst);
	if (lst->ch_ar)
	{
		lst0->mlx = lst->mlx;
		window(lst0);
	}
	instruction();
	mlx_loop(lst->mlx);
	pthread_exit(NULL);
	return (0);
}
