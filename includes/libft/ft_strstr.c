/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabraham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:56:08 by vabraham          #+#    #+#             */
/*   Updated: 2019/09/14 17:56:15 by vabraham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int i;
	int j;
	int k;

	if (!*s2)
		return ((char *)s1);
	i = 0;
	while (s1[i])
	{
		k = 0;
		j = i;
		while (s2[k] && s1[j] == s2[k++])
			j++;
		if (j - i == (int)ft_strlen(s2))
			return ((char *)(s1 + i));
		i++;
	}
	return (NULL);
}
