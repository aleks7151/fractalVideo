/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabraham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 21:43:14 by vabraham          #+#    #+#             */
/*   Updated: 2019/09/14 13:30:49 by vabraham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lsd;

	if (!(lsd = ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		lsd->content = NULL;
		lsd->content_size = 0;
	}
	else
	{
		if (!(lsd->content = ft_memalloc(content_size)))
			return (NULL);
		ft_memcpy(lsd->content, (void *)content, content_size);
		lsd->content_size = content_size;
	}
	lsd->next = NULL;
	return (lsd);
}
