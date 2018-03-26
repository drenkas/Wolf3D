/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 16:47:16 by drenkas           #+#    #+#             */
/*   Updated: 2016/12/19 16:47:16 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	new = (t_list *)ft_memalloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	if (content == NULL)
	{
		content_size = 0;
		new->content = NULL;
	}
	else
	{
		new->content = ft_memalloc(content_size);
		if (new->content == NULL)
		{
			ft_memdel((void **)&new);
			return (NULL);
		}
		ft_memcpy(new->content, content, content_size);
	}
	new->content_size = content_size;
	new->next = NULL;
	return (new);
}
