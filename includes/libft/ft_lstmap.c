/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabraham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 12:54:57 by vabraham          #+#    #+#             */
/*   Updated: 2019/09/17 18:17:33 by vabraham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *a;
	t_list *l;
	t_list *s;

	if (!lst || !f)
		return (NULL);
	a = lst;
	l = f(a);
	s = l;
	while (a->next)
	{
		a = a->next;
		l->next = f(a);
		l = l->next;
	}
	return (s);
}
