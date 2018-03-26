/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 19:43:38 by drenkas           #+#    #+#             */
/*   Updated: 2017/09/11 19:43:40 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		ft_exit(t_mlx *st, char *error)
{
	st->lock = 0;
	free_map(st, st->map);
	free(st);
	ft_error(error);
	return (0);
}

void	change_map(t_mlx *st, int key)
{
	if (key == 83)
		st->sign_arg = 0;
	else if (key == 84)
		st->sign_arg = 1;
	else if (key == 85)
		st->sign_arg = 2;
	else if (key == 86)
		st->sign_arg = 3;
	zastavka(st, key);
	install_arg(st);
	free_map(st, st->map);
	init_map(st);
	inslall(st);
	valid_map(st);
	start_bitch(st);
}

void	move_cam(t_mlx *st, int key)
{
	move_cam_dir(st, key);
	if (key == 4)
	{
		if (st->map[(int)(st->posx + st->dirx * 0.13)][(int)st->posy] == 0)
			st->posx += st->dirx * 0.13;
		if (st->map[(int)st->posx][(int)(st->posy + st->diry * 0.13)] == 0)
			st->posy += st->diry * 0.13;
	}
	else if (key == 3)
	{
		if (st->map[(int)(st->posx - st->dirx * 0.11)][(int)st->posy] == 0)
			st->posx -= st->dirx * 0.11;
		if (st->map[(int)st->posx][(int)(st->posy - st->diry * 0.11)] == 0)
			st->posy -= st->diry * 0.11;
	}
	start_bitch(st);
}

void	move_cam_dir(t_mlx *st, int key)
{
	double	olddirx;
	double	oldplanex;

	if (key == 2)
	{
		olddirx = st->dirx;
		st->dirx = st->dirx * cos(0.1) - st->diry * sin(0.1);
		st->diry = olddirx * sin(0.1) + st->diry * cos(0.1);
		oldplanex = st->planex;
		st->planex = st->planex * cos(0.1) - st->planey * sin(0.1);
		st->planey = oldplanex * sin(0.1) + st->planey * cos(0.1);
	}
	else if (key == 1)
	{
		olddirx = st->dirx;
		st->dirx = st->dirx * cos(-0.1) - st->diry * sin(-0.1);
		st->diry = olddirx * sin(-0.1) + st->diry * cos(-0.1);
		oldplanex = st->planex;
		st->planex = st->planex * cos(-0.1) - st->planey * sin(-0.1);
		st->planey = oldplanex * sin(-0.1) + st->planey * cos(-0.1);
	}
}

int		ft_key_hook(int key, t_mlx *st)
{
	if (key == 53)
		ft_exit(st, "                       THE END\n");
	else if (key == 4)
		hook_side_menu(st);
	else if (key == 123)
		move_cam(st, 1);
	else if (key == 124)
		move_cam(st, 2);
	else if (key == 125)
		move_cam(st, 3);
	else if (key == 126)
		move_cam(st, 4);
	else if (key == 36)
	{
		st->lock = 0;
		system("killall afplay 2&>/dev/null >/dev/null\n \
		afplay ./music/Centuries.mp3&");
		start_bitch(st);
	}
	else if (key <= 86 && key >= 83)
		change_map(st, key);
	else if (key == 17)
		tex_hook(st);
	return (0);
}
