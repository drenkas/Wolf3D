/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 16:54:02 by drenkas           #+#    #+#             */
/*   Updated: 2016/12/19 16:54:06 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long dick;

	dick = n;
	if (dick < 0)
	{
		ft_putchar_fd('-', fd);
		dick = dick * (-1);
	}
	if (dick >= 10)
	{
		ft_putnbr_fd(dick / 10, fd);
		ft_putnbr_fd(dick % 10, fd);
	}
	else
	{
		ft_putchar_fd((dick + '0'), fd);
	}
}
