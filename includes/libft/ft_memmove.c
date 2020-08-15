/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabraham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 18:04:59 by vabraham          #+#    #+#             */
/*   Updated: 2019/09/14 19:06:40 by vabraham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	char	*srcc;
	char	*dstc;
	size_t	i;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = -1;
	srcc = (char *)src;
	dstc = (char *)dest;
	if (srcc < dstc)
		while ((int)(--size) >= 0)
			*(dstc + size) = *(srcc + size);
	else
		while (++i < size)
			*(dstc + i) = *(srcc + i);
	return (dest);
}
