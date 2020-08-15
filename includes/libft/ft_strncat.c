/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabraham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 21:24:16 by vabraham          #+#    #+#             */
/*   Updated: 2019/09/14 17:40:23 by vabraham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (dest[i])
		i++;
	while (n-- && src[k])
		dest[i++] = src[k++];
	dest[i] = '\0';
	return (dest);
}
