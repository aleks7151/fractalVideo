/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabraham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 20:36:26 by vabraham          #+#    #+#             */
/*   Updated: 2019/09/15 15:30:43 by vabraham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t i;
	size_t j;
	size_t k;

	if (!*s2)
		return ((char *)s1);
	i = 0;
	while (i < len && s1[i])
	{
		k = 0;
		j = i;
		while (s2[k] && s1[j] == s2[k++])
			j++;
		if (j - i == ft_strlen(s2) && len - i >= ft_strlen(s2))
			return ((char *)(s1 + i));
		i++;
	}
	return (NULL);
}
