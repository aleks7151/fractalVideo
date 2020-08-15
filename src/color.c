/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabraham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 22:23:57 by vabraham          #+#    #+#             */
/*   Updated: 2019/11/11 22:23:59 by vabraham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		color1(t_lst *t, int red, int green, int blue)
{
	if (t->color == 5)
	{
		blue = 0xFF - (int)(15 * pow((1 - t->tmp), 2) * pow(t->tmp, 2) * 255);
		green = 0;
		red = 0xFF - (int)(15 * pow((1 - t->tmp), 2) * pow(t->tmp, 2) * 255);
	}
	else if (t->color == 6)
	{
		red = (int)(9 * pow((1 - t->tmp), 1) * 255);
		green = 0;
		blue = (int)(8.5 * pow((1 - t->tmp), 3) * 255);
	}
	else if (t->color == 7)
	{
		red = 0;
		blue = (int)(9 * pow((1 - t->tmp), 1) * 255);
		green = blue / 2;
	}
	else if (t->color == 8)
	{
		red = (int)(9 * (1 - t->tmp) * pow(t->tmp, 3) * 255);
		green = (int)(15 * pow((1 - t->tmp), 2) * pow(t->tmp, 2) * 255);
		blue = 0xFF - (int)(8.5 * pow((1 - t->tmp), 3) * t->tmp * 255);
	}
	return (red << 16 | green << 8 | blue);
}

int		color0(t_lst *lst, int red, int green, int blue)
{
	if (lst->color == 2)
	{
		red = 0;
		green = 0xFF - (int)(8 * pow((1 - lst->tmp),
			3) * pow(lst->tmp, 1) * 255);
		blue = 0xFF - (int)(10 * (1 - lst->tmp) * pow(lst->tmp, 3) * 255);
	}
	else if (lst->color == 3)
	{
		blue = 0xFF - (int)(9 * (1 - lst->tmp) * pow(lst->tmp, 3) * 255);
		green = 0xFF - (int)(15 *
			pow((1 - lst->tmp), 2) * pow(lst->tmp, 2) * 255);
		red = (int)(8.5 * pow((1 - lst->tmp), 3) * lst->tmp * 255);
	}
	else if (lst->color == 4)
	{
		blue = (int)(15 * pow((1 - lst->tmp), 2) * pow(lst->tmp, 2) * 255);
		green = (int)(15 * pow((1 - lst->tmp), 2) * pow(lst->tmp, 2) * 255);
		red = (int)(9 * (1 - lst->tmp) * pow(lst->tmp, 3) * 255);
	}
	return (color1(lst, red, green, blue));
}

int		color(t_lst *lst, int i)
{
	int			red;
	int			green;
	int			blue;

	red = 0;
	green = 0;
	blue = 0;
	lst->tmp = (long double)i / (long double)lst->cycle;
	if (lst->color == 0)
	{
		red = (int)(9 * (1 - lst->tmp) * pow(lst->tmp, 3) * 255);
		green = (int)(15 * pow((1 - lst->tmp), 2) * pow(lst->tmp, 2) * 255);
		blue = (int)(8.5 * pow((1 - lst->tmp), 3) * lst->tmp * 255);
	}
	else if (lst->color == 1)
	{
		red = (int)(10 * (1 - lst->tmp) * pow(lst->tmp, 3) * 255);
		green = 0;
		blue = (int)(8 * pow((1 - lst->tmp), 3) * pow(lst->tmp, 1) * 255);
	}
	return (color0(lst, red, green, blue));
}

void	each0(t_lst *lst, long double *x, long double *y, long double tmp)
{
	if (lst->fractal[0] == 'm')
	{
		tmp = *x * *x - *y * *y + lst->x_0 + lst->c;
		*y = 2 * *x * *y + lst->y_0 + lst->v;
		*x = tmp;
	}
	else if (lst->fractal[0] == 'q')
	{
		tmp = *x * *x * *x - 3 * *x * *y * *y + lst->c;
		*y = 3 * *x * *x * *y - *y * *y * *y + lst->v;
		*x = tmp;
	}
	else if (lst->fractal[0] == 'w')
	{
		tmp = *x * *x * *x - 3 * *x * *y * *y + lst->x_0 + lst->c;
		*y = 3 * *x * *x * *y - *y * *y * *y + lst->y_0 + lst->v;
		*x = tmp;
	}
	else if (lst->fractal[0] == 'j')
	{
		tmp = *x * *x - *y * *y + lst->c;
		*y = 2 * *x * *y + lst->v;
		*x = tmp;
	}
}

void	error(void)
{
	ft_putstr("Error\n");
	exit(0);
}
