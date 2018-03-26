/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 16:27:04 by drenkas           #+#    #+#             */
/*   Updated: 2016/12/19 16:27:04 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	digit(long n)
{
	size_t i;

	i = 1;
	if (n < 0)
		n = -n;
	while (n >= 10)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	long	v;
	size_t	count;
	char	*str;
	char	neg;

	v = n;
	neg = (v < 0 ? 1 : 0);
	count = digit(v);
	str = ft_strnew(count + neg);
	if (str == NULL)
		return (NULL);
	if (neg)
	{
		v = -v;
		str[0] = '-';
	}
	while (count > 0)
	{
		str[count + neg - 1] = (v % 10) + '0';
		count--;
		v /= 10;
	}
	return (str);
}
