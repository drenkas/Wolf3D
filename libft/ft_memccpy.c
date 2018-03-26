/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 15:41:58 by drenkas           #+#    #+#             */
/*   Updated: 2016/12/19 15:41:59 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*strdst;
	unsigned char	*strsrc;
	unsigned char	ch;
	size_t			i;

	i = 0;
	ch = c;
	strsrc = (unsigned char *)src;
	strdst = (unsigned char *)dst;
	if (n)
	{
		while (i < n)
		{
			strdst[i] = strsrc[i];
			if (strsrc[i] == ch)
				return (&strdst[i + 1]);
			i++;
		}
	}
	return (NULL);
}
