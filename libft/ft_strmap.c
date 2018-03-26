/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 17:30:08 by drenkas           #+#    #+#             */
/*   Updated: 2016/12/19 17:30:08 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char			*new;
	size_t			i;
	size_t			k;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	while (s[i++] != '\0')
	{
		if (f(s[i]))
			k++;
	}
	new = ft_strnew(k);
	if (!new)
		return (NULL);
	i = 0;
	k = 0;
	while (s[i] != '\0')
		if (f(s[i]))
			new[k++] = f(s[i++]);
	return (new);
}
