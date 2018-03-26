/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 18:23:04 by drenkas           #+#    #+#             */
/*   Updated: 2017/09/27 18:23:11 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	init_color(t_mlx *st)
{
	if (st->side == 0 && st->raydirx < 0)
	{
		st->color[0] = 255;
		st->color[1] = 0;
		st->color[2] = 0;
	}
	else if (st->side == 0 && st->raydirx >= 0)
	{
		st->color[0] = 0;
		st->color[1] = 255;
		st->color[2] = 0;
	}
	else if (st->side == 1 && st->raydiry >= 0)
	{
		st->color[0] = 0;
		st->color[1] = 0;
		st->color[2] = 255;
	}
	else if (st->side == 1 && st->raydiry < 0)
	{
		st->color[0] = 0;
		st->color[1] = 255;
		st->color[2] = 255;
	}
	init_color_ground(st);
}

void	init_color_ground(t_mlx *st)
{
	st->color_ground[0] = 88;
	st->color_ground[1] = 118;
	st->color_ground[2] = 39;
}

void	draw_ground(t_mlx *st, int i, int x)
{
	ft_fog(st, (abs(i - HIGH) * 0.038), 0, st->color_ground);
	put_pixel(st, x, i, 1);
}

void	init_textures3(t_mlx *st, int w, int y)
{
	st->text[8].img = mlx_xpm_file_to_image(st->mlx_ptr, "textures/level4.xpm",
	&w, &y);
	st->text[8].addr = mlx_get_data_addr(st->text[8].img, &st->text[8].bpp,
	&st->text[8].s_l, &st->text[8].end);
	st->text[7].img = mlx_xpm_file_to_image(st->mlx_ptr, "textures/level3.xpm",
	&w, &y);
	st->text[7].addr = mlx_get_data_addr(st->text[7].img, &st->text[7].bpp,
	&st->text[7].s_l, &st->text[7].end);
}
