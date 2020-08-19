/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabraham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 22:06:19 by vabraham          #+#    #+#             */
/*   Updated: 2019/11/11 22:06:23 by vabraham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		mm(int x, int y, void *l)
{
	t_lst *lst;

	lst = (t_lst*)l;
	if (!(lst->movement))
		return (0);
	lst->c = ((float)x - lst->width / 2) / (lst->width / 2);
	lst->v = ((float)y - lst->height / 2) / (lst->height / 2);
	// fon(lst);
	// fractal(l);
	mlx_put_image_to_window(lst->mlx, lst->win, lst->img, 0, 0, lst->w, lst->h, lst->c, lst->v, lst->cycle, lst->color, lst->sh_x, lst->sh_y, lst->fractal[0], WIDTH, HEIGHT);
	return (0);
}

int		mp0(int b, int x, int y, t_lst *lst)
{
	if (b == 5)
	{
		lst->w /= 1.2;
		lst->h /= 1.2;
		lst->sh_x -= lst->width / 2 - x;
		lst->sh_y -= lst->height / 2 - y;
		lst->sh_x /= 1.2;
		lst->sh_y /= 1.2;
		lst->sh_x += lst->width / 2 - x;
		lst->sh_y += lst->height / 2 - y;
	}
	else if (b == 1 && lst->movement)
		lst->movement = 0;
	else if (b == 1)
		lst->movement = 1;
	// fon(lst);
	// fractal((void *)lst);
	mlx_put_image_to_window(lst->mlx, lst->win, lst->img, 0, 0, lst->w, lst->h, lst->c, lst->v, lst->cycle, lst->color, lst->sh_x, lst->sh_y, lst->fractal[0], WIDTH, HEIGHT);
	return (0);
}

int		mp(int b, int x, int y, void *l)
{
	t_lst *lst;

	lst = (t_lst*)l;
	if (x < 0 || x >= lst->width || y < 0 || y >= lst->height)
		return (0);
	if (b == 4)
	{
		lst->w *= 1.2;
		lst->h *= 1.2;
		lst->sh_x -= lst->width / 2 - x;
		lst->sh_y -= lst->height / 2 - y;
		lst->sh_x *= 1.2;
		lst->sh_y *= 1.2;
		lst->sh_x += lst->width / 2 - x;
		lst->sh_y += lst->height / 2 - y;
	}
	return (mp0(b, x, y, lst));
}

int		close_my(void *lst)
{
	(void)lst;
	exit(0);
}

void	fon(t_lst *lst)
{
	int i;

	i = -1;
	while (++i < lst->width * lst->height)
		lst->data[i] = 0;
}
