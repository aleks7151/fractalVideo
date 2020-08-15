/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabraham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:03:05 by vabraham          #+#    #+#             */
/*   Updated: 2019/11/13 17:37:49 by vabraham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	check_argv0(int argc, char **argv, t_lst *lst, t_lst *lst0)
{
	if (argc == 1 || (argc > 3 && ft_strcmp(argv[1], "-f")) ||
		argc > 4 || (argc == 2 && !ft_strcmp(argv[1], "-f")))
	{
		ft_putstr("usage: ./fractal [-f] <fractalname(2)>['j', 'm', 'q', 'w']");
		exit(0);
	}
	if (!ft_strcmp(argv[1], "-f"))
	{
		lst->w = WIDTH / 2;
		lst->h = HEIGHT / 2;
		lst->pot = POT / 2;
		lst0->w = WIDTH / 2;
		lst0->h = HEIGHT / 2;
		lst0->pot = POT / 2;
		argv[1] = argv[2];
		if (argc == 4)
		{
			lst->ch_ar = 1;
			argv[2] = argv[3];
		}
	}
	else if (argc == 3)
		lst->ch_ar = 1;
}

void	check_argv(int argc, char **argv, t_lst *lst, t_lst *lst0)
{
	lst->w = WIDTH;
	lst->h = HEIGHT;
	lst->pot = POT;
	lst->ch_ar = 0;
	lst0->w = WIDTH;
	lst0->h = HEIGHT;
	lst0->pot = POT;
	check_argv0(argc, argv, lst, lst0);
	if (argv[1][0] != 'j' && argv[1][0] != 'm' &&
		argv[1][0] != 'q' && argv[1][0] != 'w')
		error();
	if (argc >= 3 && argv[2][0] != 'j' && argv[2][0] != 'm' &&
		argv[2][0] != 'q' && argv[2][0] != 'w')
		error();
	if (!(lst->fractal = ft_strdup(argv[1])) ||
		(argc >= 3 && !(lst0->fractal = ft_strdup(argv[2]))))
		error();
	lst->width = lst->w;
	lst->height = lst->h;
	lst0->width = lst->w;
	lst0->height = lst->h;
}

void	instruction(void)
{
	ft_putstr("\ninstruction:\n\n");
	ft_putstr("mouse left     = change (ON/OF)\n");
	ft_putstr("space          = change (ON/OF)\n");
	ft_putstr("mouse move     = change coefficient\n");
	ft_putstr("mouse zoom     = zoom\n");
	ft_putstr("arrow up, down = zoom");
	ft_putstr("up, down       = change fractal\n");
	ft_putstr("Q, E           = coefficient +- 0.01\n");
	ft_putstr("Z, X           = coefficient +- 0.001\n");
	ft_putstr("C, V           = coefficient +- 0.0001\n");
	ft_putstr("B, N           = coefficient +- 0.00001\n");
	ft_putstr("W, A, S, D     = move fractal\n");
	ft_putstr("-, +           = iterations +- 1\n");
	ft_putstr("[, ]           = iterations +- 10\n");
	ft_putstr("<, >           = change color\n");
	ft_putstr("enter          = coefficient = 0\n");
	ft_putstr("ESC            = exit\n");
}
