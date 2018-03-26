/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 18:00:35 by drenkas           #+#    #+#             */
/*   Updated: 2016/12/19 18:00:35 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	char *l;

	l = NULL;
	while (*str != '\0')
	{
		if (*str == (char)ch)
			l = (char*)str;
		str++;
	}
	if (*str == (char)ch)
		return ((char*)str);
	else
		return (l);
}
