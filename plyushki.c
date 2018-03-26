/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plyushki.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 16:54:37 by drenkas           #+#    #+#             */
/*   Updated: 2017/10/10 16:54:40 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	zastavka(t_mlx *st, int key)
{
	if (key == 83 && st->lock != 5)
	{
		st->lock = 5;
		system("killall afplay 2&>/dev/null >/dev/null\n \
		afplay ./music/Centuries.mp3&");
	}
	else if (key == 84 && st->lock != 6)
	{
		st->lock = 6;
		system("killall afplay 2&>/dev/null >/dev/null\n \
		afplay ./music/Ghostbusters.mp3&");
	}
	else if (key == 85 && st->lock != 7)
	{
		st->lock = 7;
		system("killall afplay 2&>/dev/null >/dev/null\n \
		afplay ./music/Smells.mp3&");
	}
	else if (key == 86 && st->lock != 8)
		zastavka2(st);
	else
		st->lock = 0;
}

void	zastavka2(t_mlx *st)
{
	st->lock = 8;
	system("killall afplay 2&>/dev/null >/dev/null\n \
	afplay ./music/StarWars.mp3&");
}

void	draw_side_menu(t_mlx *st)
{
	unsigned int	p;
	unsigned int	tp;
	int				x;
	int				y;

	x = 0;
	while (x < 150)
	{
		y = 0;
		while (y < HIGH)
		{
			p = x * 4 + y * (st->s_l);
			tp = x * 4 + y * (st->text[4].s_l);
			st->addr[p] = st->text[4].addr[tp];
			st->addr[p + 1] = st->text[4].addr[tp + 1];
			st->addr[p + 2] = st->text[4].addr[tp + 2];
			y++;
		}
		x++;
	}
}

void	hook_side_menu(t_mlx *st)
{
	if (st->side_lock == 0)
		st->side_lock = 1;
	else if (st->side_lock == 1)
		st->side_lock = 0;
	start_bitch(st);
}
