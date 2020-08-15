/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabraham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 21:46:03 by vabraham          #+#    #+#             */
/*   Updated: 2019/09/17 21:31:49 by vabraham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		i;
	int		k;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	str = (char *)ft_memalloc(i + 1);
	if (!str)
		return (NULL);
	k = 0;
	while (s[k])
	{
		str[k] = f(s[k]);
		k++;
	}
	str[k] = '\0';
	return (str);
}
