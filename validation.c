/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 18:47:02 by drenkas           #+#    #+#             */
/*   Updated: 2017/10/07 18:47:05 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	check_border(t_mlx *st)
{
	int i;

	i = 0;
	while (i < st->arrheight)
	{
		if (st->map[i][0] != 1)
			ft_exit(st, "Borders must be equal to 1\n");
		if (st->map[i][st->len - 1] != 1)
			ft_exit(st, "Borders must be equal to 1\n");
		i++;
	}
}

void	valid_map(t_mlx *st)
{
	check_border(st);
	if (st->posx > st->len || st->posy > st->arrheight)
		ft_exit(st, "Invalid player position\n");
	if (st->map[(int)st->posx][(int)st->posy] != 0)
		ft_exit(st, "Invalid player position\n");
	if ((st->map[(int)st->posy + 1][(int)st->posx + 1] != 0) ||
	(st->map[(int)st->posy + 1][(int)st->posx] != 0) ||
	(st->map[(int)st->posy][(int)st->posx + 1] != 0) ||
	(st->map[(int)st->posy - 1][(int)st->posx - 1] != 0) ||
	(st->map[(int)st->posy - 1][(int)st->posx] != 0) ||
	(st->map[(int)st->posy][(int)st->posx - 1] != 0))
		ft_exit(st, "Invalid player position, player can't move\n");
}

void	free_split(char **str)
{
	int		i;

	i = -1;
	while (str[++i] != NULL)
		free(str[i]);
	free(str);
}

void	free_map(t_mlx *st, int **str)
{
	int		i;

	i = -1;
	while (++i < st->arrheight)
		free(str[i]);
	free(str);
}

int		ft_exit_hook(t_mlx *st)
{
	st->lock = 0;
	free_map(st, st->map);
	free(st);
	ft_error("                       THE END\n");
	return (0);
}
