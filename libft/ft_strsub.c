/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 18:05:14 by drenkas           #+#    #+#             */
/*   Updated: 2016/12/19 18:05:14 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int begin, size_t len)
{
	char	*new;
	size_t	i;

	if (s)
	{
		i = 0;
		new = ft_strnew(len);
		if (new == NULL)
			return (NULL);
		while (i < len)
		{
			new[i] = s[begin + i];
			i++;
		}
		return (new);
	}
	return (NULL);
}
