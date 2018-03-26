/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 15:50:30 by drenkas           #+#    #+#             */
/*   Updated: 2016/12/19 15:50:32 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		print_nb(int nb)
{
	char	output[10];
	int		i;

	i = 0;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	while (nb > 9)
	{
		output[i] = nb % 10 + 48;
		nb = nb / 10;
		i++;
	}
	if (nb <= 9)
	{
		output[i] = nb + 48;
	}
	while (i >= 0)
	{
		ft_putchar(output[i]);
		i--;
	}
}

void			ft_putnbr(int nb)
{
	if (nb != -2147483648)
	{
		if (nb != 0)
		{
			print_nb(nb);
		}
		else
			ft_putchar(48);
	}
	else
	{
		ft_putchar('-');
		print_nb(2147483);
		print_nb(648);
	}
}
