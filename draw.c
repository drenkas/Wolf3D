/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 19:42:03 by drenkas           #+#    #+#             */
/*   Updated: 2017/09/11 19:42:07 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	draw_sky(t_mlx *st)
{
	unsigned int	p;
	int				x;
	int				y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HIGH / 2)
		{
			p = x * 4 + y * (st->s_l);
			st->addr[p] = st->text[0].addr[p];
			st->addr[p + 1] = st->text[0].addr[p + 1];
			st->addr[p + 2] = st->text[0].addr[p + 2];
			y++;
		}
		x++;
	}
}

void	draw_menu(t_mlx *st, int k)
{
	unsigned int	p;
	int				x;
	int				y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HIGH)
		{
			p = x * 4 + y * (st->s_l);
			st->addr[p] = st->text[k].addr[p];
			st->addr[p + 1] = st->text[k].addr[p + 1];
			st->addr[p + 2] = st->text[k].addr[p + 2];
			y++;
		}
		x++;
	}
}

void	put_pixel(t_mlx *st, int x, int y, int k)
{
	unsigned int	p;

	p = x * 4 + y * (st->s_l);
	if (k == 1)
	{
		st->addr[p] = mlx_get_color_value(st->mlx_ptr, st->color_gr[0]);
		st->addr[p + 1] = mlx_get_color_value(st->mlx_ptr, st->color_gr[1]);
		st->addr[p + 2] = mlx_get_color_value(st->mlx_ptr, st->color_gr[2]);
	}
	else
	{
		st->addr[p] = mlx_get_color_value(st->mlx_ptr, st->color[0]);
		st->addr[p + 1] = mlx_get_color_value(st->mlx_ptr, st->color[1]);
		st->addr[p + 2] = mlx_get_color_value(st->mlx_ptr, st->color[2]);
	}
}

void	ft_fog(t_mlx *st, double dist, int k, int *color)
{
	double	d;

	d = 6 / (100 / dist);
	if (d > 0.9)
		d = 0.9;
	if (k == 1)
	{
		if (color[0] > 0)
			st->color[0] = color[0] - (color[0] * d);
		if (color[1] > 0)
			st->color[1] = color[1] - (color[1] * d);
		if (color[2] > 0)
			st->color[2] = color[2] - (color[2] * d);
	}
	else
	{
		if (st->color_ground[0] > 0)
			st->color_gr[0] = st->color_ground[0] - (st->color_ground[0] * d);
		if (st->color_ground[1] > 0)
			st->color_gr[1] = st->color_ground[1] - (st->color_ground[1] * d);
		if (st->color_ground[2] > 0)
			st->color_gr[2] = st->color_ground[2] - (st->color_ground[2] * d);
	}
}

void	drawline(t_mlx *st, int x)
{
	int y;
	int i;

	y = st->drawstart - 1;
	if (st->tex_lock == 0)
	{
		init_color(st);
		ft_fog(st, st->perpwalldist, 1, st->color);
		while (++y < st->drawend)
			put_pixel(st, x, y, 9);
	}
	else
	{
		ft_texture_hit(st);
		while (++y < st->drawend)
		{
			st->t_y = abs(((y * 64 - HIGH * 32 + st->lineh * 32)
			* 64) / st->lineh) / 64;
			textured_draw(st, x, y);
		}
	}
	i = st->drawend - 1;
	while (++i < HIGH)
		draw_ground(st, i, x);
}
