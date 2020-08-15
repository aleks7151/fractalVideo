/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabraham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 22:46:02 by vabraham          #+#    #+#             */
/*   Updated: 2019/11/08 22:46:03 by vabraham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		kp3(int key, t_lst *lst)
{
	if (key == 121)
	{
		if (lst->fractal[0] == 'j')
			lst->fractal[0] = 'w';
		else if (lst->fractal[0] == 'm')
			lst->fractal[0] = 'j';
		else if (lst->fractal[0] == 'q')
			lst->fractal[0] = 'm';
		else if (lst->fractal[0] == 'w')
			lst->fractal[0] = 'q';
	}
	else if (key == 36)
	{
		lst->c = 0;
		lst->v = 0;
	}
	if (lst->color < 0)
		lst->color = 8;
	else if (lst->color > 8)
		lst->color = 0;
	fon(lst);
	fractal((void *)lst);
	mlx_put_image_to_window(lst->mlx, lst->win, lst->img, 0, 0, lst->w, lst->h, lst->c, lst->v, lst->cycle, lst->color, lst->sh_x, lst->sh_y, lst->fractal[0], WIDTH, HEIGHT);
	return (0);
}

int		kp2(int key, t_lst *lst)
{
	if (key == 33 && lst->cycle - 1 > 0)
		lst->cycle -= 10;
	else if (key == 30)
		lst->cycle += 10;
	else if (key == 43)
		lst->color--;
	else if (key == 47)
		lst->color++;
	else if (key == 49 && lst->movement)
		lst->movement = 0;
	else if (key == 49)
		lst->movement = 1;
	else if (key == 116)
	{
		if (lst->fractal[0] == 'j')
			lst->fractal[0] = 'm';
		else if (lst->fractal[0] == 'm')
			lst->fractal[0] = 'q';
		else if (lst->fractal[0] == 'q')
			lst->fractal[0] = 'w';
		else if (lst->fractal[0] == 'w')
			lst->fractal[0] = 'j';
	}
	return (kp3(key, lst));
}

int		kp1(int key, t_lst *lst)
{
	if (key == 8)
	{
		lst->c += 0.0001;
		lst->v += 0.0001;
	}
	else if (key == 9)
	{
		lst->c -= 0.0001;
		lst->v -= 0.0001;
	}
	else if (key == 11)
	{
		lst->c += 0.00001;
		lst->v += 0.00001;
	}
	else if (key == 45)
	{
		lst->c -= 0.00001;
		lst->v -= 0.00001;
	}
	else if (key == 27 && lst->cycle - 1 > 0)
		lst->cycle--;
	else if (key == 24)
		lst->cycle++;
	return (kp2(key, lst));
}

int		kp0(int key, t_lst *lst)
{
	if (key == 0)
		lst->sh_x -= 40;
	else if (key == 2)
		lst->sh_x += 40;
	else if (key == 12)
	{
		lst->c += 0.01;
		lst->v += 0.01;
	}
	else if (key == 14)
	{
		lst->c -= 0.01;
		lst->v -= 0.01;
	}
	else if (key == 6)
	{
		lst->c += 0.001;
		lst->v += 0.001;
	}
	else if (key == 7)
	{
		lst->c -= 0.001;
		lst->v -= 0.001;
	}
	return (kp1(key, lst));
}

int		kp(int key, void *l)
{
	t_lst *lst;

	lst = (t_lst*)l;
	if (key == 53)
		exit(0);
	else if (key == 125)
	{
		lst->w *= 1.2;
		lst->h *= 1.2;
		lst->sh_x *= 1.2;
		lst->sh_y *= 1.2;
	}
	else if (key == 126)
	{
		lst->w /= 1.2;
		lst->h /= 1.2;
		lst->sh_x /= 1.2;
		lst->sh_y /= 1.2;
	}
	else if (key == 13)
		lst->sh_y -= 40;
	else if (key == 1)
		lst->sh_y += 40;
	return (kp0(key, lst));
}
