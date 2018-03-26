/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 17:48:05 by drenkas           #+#    #+#             */
/*   Updated: 2016/12/19 17:48:06 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	size_t i;
	size_t j;

	if (*str2 == '\0')
		return ((char *)str1);
	i = 0;
	while (str1[i] && i < n)
	{
		j = 0;
		while (str1[i + j] && i + j < n && str2[j] && str1[i + j] == str2[j])
			j++;
		if (str2[j] == '\0')
			return ((char *)(str1 + i));
		i++;
	}
	return (NULL);
}
