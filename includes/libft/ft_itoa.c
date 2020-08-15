/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabraham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 20:09:16 by vabraham          #+#    #+#             */
/*   Updated: 2019/09/14 18:39:26 by vabraham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(int n)
{
	int i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 9)
	{
		i++;
		n /= 10;
	}
	return (i + 1);
}

static void	ft_getnbr(char *s, int *i, int n)
{
	if (n < 10)
	{
		s[*i] = n + 48;
		*i += 1;
		return ;
	}
	ft_getnbr(s, i, n / 10);
	s[*i] = (n % 10) + 48;
	*i += 1;
}

static char	*iskl(char *s)
{
	char	*s0;
	int		i;

	s = ft_memalloc(12);
	s[0] = '-';
	s[1] = '2';
	s0 = ft_itoa(147483648);
	i = -1;
	while (s0[++i])
		s[i + 2] = s0[i];
	return (s);
}

char		*ft_itoa(int n)
{
	int		i;
	char	*s;

	s = NULL;
	if (n == -2147483648)
		return (iskl(s));
	i = check(n);
	s = ft_memalloc(i + 1);
	if (!s)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		s[i++] = '-';
		n *= -1;
	}
	ft_getnbr(s, &i, n);
	s[i] = '\0';
	return (s);
}
