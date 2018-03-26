/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 20:35:36 by drenkas           #+#    #+#             */
/*   Updated: 2017/01/28 20:35:37 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Creates list element and connects it to back
*/

t_gnl		*ft_create(int fd, char *bufline, t_gnl **begin)
{
	t_gnl	*tmp;
	t_gnl	*lst;

	tmp = (t_gnl *)malloc(sizeof(t_gnl));
	if (!tmp)
		return (NULL);
	tmp->fd = fd;
	tmp->content = ft_strdup(bufline);
	tmp->next = NULL;
	lst = *begin;
	if (*begin == NULL)
		*begin = tmp;
	else
	{
		while (lst->next)
			lst = lst->next;
		lst->next = tmp;
	}
	return (tmp);
}

/*
** Search list element that contain needed fd
*/

t_gnl		*ft_list_search(int fd, t_gnl **begin)
{
	t_gnl	*tmp;

	tmp = *begin;
	while (tmp && tmp->fd != fd)
		tmp = tmp->next;
	return (tmp);
}

/*
** Split line before and after '\n'
** Return content before and write to list content after '\n'
*/

char		*ft_line(int fd, t_gnl **begin)
{
	t_gnl	*elem;
	char	*end;
	char	*bgn;
	char	*tmp;

	elem = ft_list_search(fd, begin);
	if (elem->content == NULL || elem->content[0] == '\0')
		return (NULL);
	if ((end = ft_strchr(elem->content, '\n')) != NULL)
	{
		end[0] = '\0';
		if (!(bgn = ft_strsub(elem->content, 0, ft_strlen(elem->content))))
			return (NULL);
		tmp = elem->content;
		elem->content = ft_strdup(++end);
		free(tmp);
	}
	else
	{
		if (!(bgn = ft_strdup(elem->content)))
			return (NULL);
		free(elem->content);
		elem->content = NULL;
	}
	return (bgn);
}

/*
** Creates list element and joining element content with buf
** If it find '\n' in content – return 1
*/

int			ft_gnl_create(int fd, char *buf, t_gnl **begin)
{
	t_gnl	*elem;
	char	*str;

	elem = ft_list_search(fd, begin);
	if (elem == NULL)
		elem = ft_create(fd, buf, begin);
	else
	{
		if (!(str = ft_strjoin((char *)elem->content, buf)))
			return (ERR);
		free(elem->content);
		elem->content = str;
	}
	if (ft_strchr(elem->content, '\n') != NULL)
		return (1);
	return (0);
}

/*
** Main function. Reads the buffer and calling create function
** Return 1 if line written and 0 if reading end
*/

int			get_next_line(int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	int				rd;
	static t_gnl	lst;
	t_gnl			*begin;
	int				bad_boy;

	begin = &lst;
	if (fd < 0 || line == NULL)
		return (ERR);
	while ((rd = read(fd, buf, BUFF_SIZE)) != 0 && BUFF_SIZE < 65536)
	{
		if (rd < 0)
			return (ERR);
		buf[rd] = '\0';
		if ((bad_boy = ft_gnl_create(fd, buf, &begin)) == 1)
		{
			*line = (char *)ft_line(fd, &begin);
			return (TRUE);
		}
		else if (bad_boy == ERR)
			return (ERR);
	}
	if ((*line = (char *)ft_line(fd, &begin)) != NULL)
		return (TRUE);
	return (DONE);
}
