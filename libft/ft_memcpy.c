/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 15:44:23 by drenkas           #+#    #+#             */
/*   Updated: 2016/12/19 15:44:23 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *d;
	unsigned char *s;

	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	if (n)
	{
		while (n--)
		{
			*d = *s;
			d++;
			s++;
		}
	}
	return (dst);
}
