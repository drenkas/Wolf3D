/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 16:45:09 by drenkas           #+#    #+#             */
/*   Updated: 2016/12/19 16:45:09 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *el))
{
	t_list	*el;
	t_list	*first;

	el = ft_lstnew(lst->content, lst->content_size);
	if (el == NULL)
		return (NULL);
	el = (*f)(el);
	first = el;
	while (lst->next)
	{
		lst = lst->next;
		el->next = ft_lstnew(lst->content, lst->content_size);
		el->next = (*f)(el->next);
		el = el->next;
	}
	return (first);
}
