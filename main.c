/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 16:19:33 by drenkas           #+#    #+#             */
/*   Updated: 2017/09/09 16:19:43 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	inslall(t_mlx *st)
{
	st->posx = 2;
	st->posy = 2;
	st->dirx = 1;
	st->diry = 0;
	st->planex = 0;
	st->planey = 0.66;
	init_textures(st);
}

void	install_arg(t_mlx *st)
{
	if (st->sign_arg == 0)
		st->arg = ft_strdup("maps/map.wolf");
	else if (st->sign_arg == 1)
		st->arg = ft_strdup("maps/map1.wolf");
	else if (st->sign_arg == 2)
		st->arg = ft_strdup("maps/map2.wolf");
	else if (st->sign_arg == 3)
		st->arg = ft_strdup("maps/map3.wolf");
}

void	start_bitch(t_mlx *st)
{
	mlx_destroy_image(st->mlx_ptr, st->img);
	mlx_clear_window(st->mlx_ptr, st->win_prt);
	st->img = mlx_new_image(st->mlx_ptr, WIDTH, HIGH);
	st->addr = mlx_get_data_addr(st->img, &st->bpp, &st->s_l, &st->end);
	if (st->lock >= 5 && st->lock <= 8)
		draw_menu(st, st->lock);
	if (st->lock == 1)
		draw_menu(st, 3);
	if (st->lock == 0)
	{
		draw_sky(st);
		init_ray(st);
		if (st->side_lock == 1)
			draw_side_menu(st);
	}
	mlx_put_image_to_window(st->mlx_ptr, st->win_prt, st->img, 0, 0);
}

void	main_start(t_mlx *st)
{
	install_arg(st);
	init_map(st);
	st->mlx_ptr = mlx_init();
	st->win_prt = mlx_new_window(st->mlx_ptr, WIDTH, HIGH, "Wolf3D by Nakers");
	st->img = mlx_new_image(st->mlx_ptr, WIDTH, HIGH);
	st->addr = mlx_get_data_addr(st->img, &st->bpp, &st->s_l, &st->end);
	inslall(st);
	valid_map(st);
	start_bitch(st);
	mlx_hook(st->win_prt, 2, 5, ft_key_hook, st);
	mlx_hook(st->win_prt, 17, (1L << 17), ft_exit_hook, st);
	mlx_loop(st->mlx_ptr);
}

int		main(int ac, char **av)
{
	t_mlx	*st;

	st = (t_mlx *)malloc(sizeof(t_mlx));
	if (ac != 1)
		ft_exit(st, "No files or too many! Please give me ONE file/map !\n");
	if (!av)
		ft_exit(st, "No files or too many! Please give me ONE file/map !\n");
	st->lock = 1;
	st->sign_arg = 0;
	st->tex_lock = 0;
	st->side_lock = 1;
	system("afplay ./music/Game.mp3&");
	main_start(st);
	return (0);
}
