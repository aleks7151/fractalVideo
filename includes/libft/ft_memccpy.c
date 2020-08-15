/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabraham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 23:42:34 by vabraham          #+#    #+#             */
/*   Updated: 2019/09/15 18:54:55 by vabraham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int n, size_t size)
{
	size_t	i;

	i = 0;
	while (i != size)
	{
		if (((unsigned char *)dest) == ((unsigned char *)src))
			break ;
		if (*((unsigned char *)src) == (unsigned char)n)
		{
			(*(unsigned char *)dest++) = (unsigned char)n;
			return ((unsigned char *)dest);
		}
		*((unsigned char *)dest++) = *((unsigned char *)src++);
		i++;
	}
	return (NULL);
}
