/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 16:25:50 by gmachado          #+#    #+#             */
/*   Updated: 2018/11/17 16:52:22 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*old;
	t_list	*new;
	t_list	*begin;

	if (!lst || !f)
		return (NULL);
	old = f(lst);
	new = ft_lstnew(old->content, old->content_size);
	if (!new)
		return (NULL);
	lst = lst->next;
	begin = new;
	while (lst)
	{
		old = f(lst);
		new->next = ft_lstnew(old->content, old->content_size);
		if (!new->next)
			return (NULL);
		lst = lst->next;
		new = new->next;
	}
	return (begin);
}
