/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 14:24:44 by drenkas           #+#    #+#             */
/*   Updated: 2017/10/05 14:24:48 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	init_textures(t_mlx *st)
{
	int		w;
	int		y;

	w = 800;
	y = 400;
	st->text[0].img = mlx_xpm_file_to_image(st->mlx_ptr, "textures/sky.xpm",
	&w, &y);
	st->text[0].addr = mlx_get_data_addr(st->text[0].img, &st->text[0].bpp,
	&st->text[0].s_l, &st->text[0].end);
	w = 64;
	y = 64;
	st->text[2].img = mlx_xpm_file_to_image(st->mlx_ptr, "textures/mossy.xpm",
	&w, &y);
	st->text[2].addr = mlx_get_data_addr(st->text[2].img, &st->text[2].bpp,
	&st->text[2].s_l, &st->text[2].end);
	st->text[1].img = mlx_xpm_file_to_image(st->mlx_ptr, "textures/redb.xpm",
	&w, &y);
	st->text[1].addr = mlx_get_data_addr(st->text[1].img, &st->text[1].bpp,
	&st->text[1].s_l, &st->text[1].end);
	st->text[9].img = mlx_xpm_file_to_image(st->mlx_ptr, "textures/moshi.xpm",
	&w, &y);
	st->text[9].addr = mlx_get_data_addr(st->text[9].img, &st->text[9].bpp,
	&st->text[9].s_l, &st->text[9].end);
	init_textures2(st, w, y);
}

void	init_textures2(t_mlx *st, int w, int y)
{
	w = 150;
	y = 800;
	st->text[4].img = mlx_xpm_file_to_image(st->mlx_ptr, "textures/sidem.xpm",
	&w, &y);
	st->text[4].addr = mlx_get_data_addr(st->text[4].img, &st->text[4].bpp,
	&st->text[4].s_l, &st->text[4].end);
	w = 800;
	st->text[3].img = mlx_xpm_file_to_image(st->mlx_ptr, "textures/menu.xpm",
	&w, &y);
	st->text[3].addr = mlx_get_data_addr(st->text[3].img, &st->text[3].bpp,
	&st->text[3].s_l, &st->text[3].end);
	st->text[5].img = mlx_xpm_file_to_image(st->mlx_ptr, "textures/level1.xpm",
	&w, &y);
	st->text[5].addr = mlx_get_data_addr(st->text[5].img, &st->text[5].bpp,
	&st->text[5].s_l, &st->text[5].end);
	st->text[6].img = mlx_xpm_file_to_image(st->mlx_ptr, "textures/level2.xpm",
	&w, &y);
	st->text[6].addr = mlx_get_data_addr(st->text[6].img, &st->text[6].bpp,
	&st->text[6].s_l, &st->text[6].end);
	init_textures3(st, w, y);
}

void	ft_texture_hit(t_mlx *st)
{
	double	wall_x;

	if ((st->num_tex = st->map[st->mapx][st->mapy]) > 2)
		st->num_tex = 9;
	if (st->side == 0)
		wall_x = st->rayposy + st->perpwalldist * st->raydiry;
	else
		wall_x = st->rayposx + st->perpwalldist * st->raydirx;
	wall_x -= floor(wall_x);
	st->t_x = (int)(wall_x * (double)64);
	if ((st->side == 0 && st->raydirx > 0) ||
	(st->side == 1 && st->raydirx < 0))
		st->t_x = 64 - st->t_x - 1;
	st->t_x = abs(st->t_x);
}

void	textured_draw(t_mlx *st, int x, int y)
{
	unsigned int	p;
	unsigned int	tex_p;
	int				color[3];

	p = x * 4 + y * (st->s_l);
	tex_p = 64 * st->t_y * 4 + st->t_x % 64 * 4;
	color[0] = st->text[st->num_tex].addr[tex_p];
	color[1] = st->text[st->num_tex].addr[tex_p + 1];
	color[2] = st->text[st->num_tex].addr[tex_p + 2];
	color[0] = color[0] < 0 ? (255 + color[0]) : color[0];
	color[1] = color[1] < 0 ? (255 + color[1]) : color[1];
	color[2] = color[2] < 0 ? (255 + color[2]) : color[2];
	st->color[2] = 0;
	st->color[1] = 0;
	st->color[0] = 0;
	ft_fog(st, st->perpwalldist, 1, color);
	st->addr[p] = st->color[0];
	st->addr[p + 1] = st->color[1];
	st->addr[p + 2] = st->color[2];
	st->addr[p + 3] = st->text[st->num_tex].addr[tex_p + 3];
}

void	tex_hook(t_mlx *st)
{
	if (st->tex_lock == 0)
		st->tex_lock = 1;
	else
		st->tex_lock = 0;
	start_bitch(st);
}
