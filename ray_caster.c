/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_caster.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 19:35:50 by drenkas           #+#    #+#             */
/*   Updated: 2017/09/11 19:35:55 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	init_ray_start(t_mlx *st, int x)
{
	st->camerax = 2 * x / (double)WIDTH - 1;
	st->rayposx = st->posx;
	st->rayposy = st->posy;
	st->raydirx = st->dirx + st->planex * st->camerax;
	st->raydiry = st->diry + st->planey * st->camerax;
	st->mapx = (int)st->rayposx;
	st->mapy = (int)st->rayposy;
	st->hit = 0;
	st->deltadistx = sqrt(1 + (st->raydiry * st->raydiry) /
	(st->raydirx * st->raydirx));
	st->deltadisty = sqrt(1 + (st->raydirx * st->raydirx) /
	(st->raydiry * st->raydiry));
}

void	init_ray_if(t_mlx *st)
{
	if (st->raydirx < 0)
	{
		st->stepx = -1;
		st->sidedistx = (st->rayposx - st->mapx) * st->deltadistx;
	}
	else
	{
		st->stepx = 1;
		st->sidedistx = (st->mapx + 1.0 - st->rayposx) * st->deltadistx;
	}
	if (st->raydiry < 0)
	{
		st->stepy = -1;
		st->sidedisty = (st->rayposy - st->mapy) * st->deltadisty;
	}
	else
	{
		st->stepy = 1;
		st->sidedisty = (st->mapy + 1.0 - st->rayposy) * st->deltadisty;
	}
}

void	init_ray_hit(t_mlx *st)
{
	while (st->hit == 0)
	{
		if (st->sidedistx < st->sidedisty)
		{
			st->sidedistx += st->deltadistx;
			st->mapx += st->stepx;
			st->side = 0;
		}
		else
		{
			st->sidedisty += st->deltadisty;
			st->mapy += st->stepy;
			st->side = 1;
		}
		if (st->map[st->mapx][st->mapy] > 0)
		{
			st->hit = 1;
		}
	}
}

void	init_ray(t_mlx *st)
{
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		init_ray_start(st, x);
		init_ray_if(st);
		init_ray_hit(st);
		if (st->side == 0)
			st->perpwalldist = (st->mapx - st->rayposx +
			(1 - st->stepx) / 2) / st->raydirx;
		else
			st->perpwalldist = (st->mapy - st->rayposy +
				(1 - st->stepy) / 2) / st->raydiry;
		st->lineh = (int)(HIGH / st->perpwalldist);
		st->drawstart = -st->lineh / 2 + HIGH / 2;
		if (st->drawstart < 0)
			st->drawstart = 0;
		st->drawend = st->lineh / 2 + HIGH / 2;
		if (st->drawend >= HIGH)
			st->drawend = HIGH - 1;
		drawline(st, x);
		x++;
	}
}
