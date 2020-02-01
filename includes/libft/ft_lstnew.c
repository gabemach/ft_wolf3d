/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 15:21:21 by gmachado          #+#    #+#             */
/*   Updated: 2018/11/17 17:06:24 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*output;

	output = (t_list*)malloc(sizeof(t_list));
	if (!output)
		return (NULL);
	if (content == NULL)
	{
		output->content = NULL;
		output->content_size = 0;
	}
	else
	{
		output->content = (void*)malloc(sizeof(size_t) * content_size);
		if (!output->content)
			return (NULL);
		output->content_size = content_size;
		ft_memcpy(output->content, content, content_size);
	}
	output->next = NULL;
	return (output);
}
