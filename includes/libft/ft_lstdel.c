/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabraham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 22:50:51 by vabraham          #+#    #+#             */
/*   Updated: 2019/09/14 18:34:45 by vabraham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *a;
	t_list *b;

	if (!alst || !del)
		return ;
	a = *alst;
	while (a)
	{
		b = a->next;
		ft_lstdelone(&a, del);
		a = b;
	}
	*alst = NULL;
}
