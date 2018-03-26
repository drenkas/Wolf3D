/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 18:02:14 by drenkas           #+#    #+#             */
/*   Updated: 2016/12/19 18:02:15 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*next_w(char const *s, char c)
{
	while (*s && *s == c)
		s++;
	return ((char *)s);
}

static	size_t	ft_countword(char *str, char sep)
{
	size_t result;
	size_t i;

	i = 0;
	result = 0;
	while (str[i] && str[i] == sep)
		i++;
	while (str[i])
	{
		while (str[i] && str[i] != sep)
			i++;
		result++;
		while (str[i] && str[i] == sep)
			i++;
	}
	return (result);
}

static	size_t	len(char const *s, char c)
{
	size_t i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**split;
	size_t	count;
	size_t	i;

	if (!s)
		return (NULL);
	count = ft_countword((char *)s, c);
	split = (char **)ft_memalloc((count + 1) * sizeof(char *));
	if (split == NULL)
		return (NULL);
	i = 0;
	while (i < count)
	{
		s = next_w(s, c);
		split[i] = ft_strsub(s, 0, len(s, c));
		if (split[i] == NULL)
		{
			return (NULL);
		}
		i++;
		s += len(s, c);
	}
	split[count] = NULL;
	return (split);
}
