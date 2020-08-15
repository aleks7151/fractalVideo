/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabraham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 23:51:48 by vabraham          #+#    #+#             */
/*   Updated: 2019/09/14 17:29:20 by vabraham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *dest, int c, size_t n)
{
	char	*a;
	char	*arr;
	int		i;

	arr = (char *)dest;
	a = arr;
	i = 0;
	while (n--)
	{
		if (arr[i] == (char)c)
			return (a + i);
		i++;
	}
	return (NULL);
}
