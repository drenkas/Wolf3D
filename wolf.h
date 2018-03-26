/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 19:22:26 by drenkas           #+#    #+#             */
/*   Updated: 2017/04/25 19:22:27 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./libft/libft.h"
# include "./mlx/mlx.h"
# include <math.h>
# include <pthread.h>
# define RED "\033[02;31m"
# define OK "\033[32m"
# define HIGH 800
# define WIDTH 800
# define S_L thr->mlx->s_l
# define OBJ st->obj
# define MLX st->mlx_ptr
# define WIN st->win_prt

typedef struct			s_tex
{
	void				*img;
	int					bpp;
	int					s_l;
	int					end;
	char				*addr;
}						t_tex;

typedef struct			s_mlx
{
	void				*mlx_ptr;
	void				*win_prt;
	void				*img;
	int					bpp;
	int					s_l;
	int					end;
	char				*addr;
	int					**map;
	char				*arg;
	int					sign_arg;
	int					maph;
	int					mapw;
	double				posx;
	double				posy;
	double				dirx;
	double				diry;
	double				planex;
	double				planey;
	double				camerax;
	double				rayposx;
	double				rayposy;
	double				raydirx;
	double				raydiry;
	int					mapx;
	int					mapy;
	double				sidedistx;
	double				sidedisty;
	double				deltadistx;
	double				deltadisty;
	int					stepx;
	int					stepy;
	double				perpwalldist;
	int					hit;
	int					side;
	int					lineh;
	int					drawstart;
	int					drawend;
	int					arrheight;
	int					color[3];
	int					color_ground[3];
	int					color_gr[3];
	int					lock;
	int					tex_lock;
	t_tex				text[10];
	int					num_tex;
	int					t_x;
	int					t_y;
	int					side_lock;
	int					prev_len;
	int					len;
}						t_mlx;

void					main_start(t_mlx *st);
void					init_map(t_mlx *st);
int						**init_first();
void					start_bitch(t_mlx *mlx);
int						ft_key_hook(int key, t_mlx *st);
void					move_cam(t_mlx *st, int key);
int						ft_exit(t_mlx *st, char *error);
void					inslall(t_mlx *st);
void					drawline(t_mlx *st, int x);
void					put_pixel(t_mlx *st, int x, int y, int k);
void					init_ray(t_mlx *st);
void					ft_open(t_mlx *st);
void					init_color(t_mlx *st);
void					draw_sky(t_mlx *st);
void					init_textures(t_mlx *st);
void					draw_menu(t_mlx *st, int k);
void					ft_fog(t_mlx *st, double dist, int k, int *color);
void					install_arg(t_mlx *st);
void					change_map(t_mlx *st, int key);
void					textured_draw(t_mlx *st, int x, int y);
void					ft_texture_hit(t_mlx *st);
void					tex_hook(t_mlx *st);
void					init_textures2(t_mlx *st, int x, int y);
void					init_textures3(t_mlx *st, int x, int y);
void					zastavka(t_mlx *st, int key);
void					draw_side_menu(t_mlx *st);
void					hook_side_menu(t_mlx *st);
void					check_border(t_mlx *st);
void					valid_map(t_mlx *st);
void					write_map(t_mlx *st, int i[2], char **strs);
void					init_color_ground(t_mlx *st);
void					draw_ground(t_mlx *st, int i, int x);
void					move_cam_dir(t_mlx *st, int key);
int						open_map(t_mlx *st, int fd);
void					init_ray_hit(t_mlx *st);
void					init_ray_if(t_mlx *st);
void					init_ray_start(t_mlx *st, int x);
void					free_split(char **str);
void					free_map(t_mlx *st, int **str);
int						ft_exit_hook(t_mlx *st);
void					zastavka2(t_mlx *st);
#endif
