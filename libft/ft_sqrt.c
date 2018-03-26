/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 16:39:14 by drenkas           #+#    #+#             */
/*   Updated: 2016/12/21 16:39:14 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(int nb)
{
	int		ans;
	int		sqr;

	if (nb <= 0)
		return (0);
	ans = 1;
	sqr = 1;
	while (sqr < nb && ++ans)
		sqr = ans * ans;
	if (sqr > nb)
		return (0);
	else
		return (ans);
}
