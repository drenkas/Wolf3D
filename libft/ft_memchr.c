/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 15:42:50 by drenkas           #+#    #+#             */
/*   Updated: 2016/12/19 15:42:51 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*src;
	size_t			i;

	i = 0;
	src = (unsigned char *)str;
	while (n > 0 && *src != (unsigned char)c)
	{
		n--;
		src++;
	}
	if (n == 0)
		return (NULL);
	else
		return (src);
	return (NULL);
}
