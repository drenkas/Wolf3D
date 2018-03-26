/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 15:46:01 by drenkas           #+#    #+#             */
/*   Updated: 2016/12/19 15:46:02 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dst, int c, size_t n)
{
	unsigned char *d;

	d = (unsigned char*)dst;
	if (n)
	{
		while (n--)
		{
			*d = c;
			d++;
		}
	}
	return (dst);
}
