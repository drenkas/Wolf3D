/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 16:18:38 by drenkas           #+#    #+#             */
/*   Updated: 2017/09/09 16:18:53 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		array_len(char **strs)
{
	int i;

	i = 0;
	while (strs[i] != NULL)
		i++;
	return (i);
}

int		open_map(t_mlx *st, int fd)
{
	char	*line;

	st->arrheight = 0;
	if ((fd = open(st->arg, O_RDONLY)) == -1)
		ft_exit(st, "open failed on input file");
	while (get_next_line(fd, &line) != 0)
	{
		st->arrheight++;
		free(line);
	}
	free(line);
	if ((fd = open(st->arg, O_RDONLY)) == -1)
		ft_exit(st, "open failed on input file");
	free(st->arg);
	st->map = (int **)malloc(sizeof(int *) * st->arrheight);
	return (fd);
}

void	write_map(t_mlx *st, int i[2], char **strs)
{
	st->len = array_len(strs);
	if (i[0] != 0)
		if (st->prev_len != st->len)
			ft_exit(st, "Invalid map. The lines must be equal.\n");
	st->prev_len = st->len;
	st->map[i[0]] = (int *)malloc(sizeof(int) * st->len);
	while (i[1] < st->len)
	{
		st->map[i[0]][i[1]] = ft_atoi(strs[i[1]]);
		i[1]++;
	}
}

void	init_map(t_mlx *st)
{
	int		fd;
	char	*line;
	char	**strs;
	int		i[2];

	i[0] = 0;
	fd = 0;
	fd = open_map(st, fd);
	while (get_next_line(fd, &line) != 0)
	{
		i[1] = 0;
		strs = ft_strsplit(line, ' ');
		free(line);
		write_map(st, i, strs);
		i[0]++;
		free_split(strs);
	}
	free(line);
}
