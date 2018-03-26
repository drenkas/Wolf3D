/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 18:12:09 by drenkas           #+#    #+#             */
/*   Updated: 2016/12/19 18:12:10 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# define RED "\033[02;31m"
# define BUFF_SIZE 100
# define ERR -1
# define TRUE 1
# define DONE 0

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_lst
{
	char			*content;
	int				fd;
	struct s_lst	*next;
}					t_gnl;

void				*ft_memset(void *s, int i, size_t len);
void				ft_bzero(void *s, size_t len);
void				ft_error(char *error);
void				*ft_memcpy(void *s, const void *d, size_t len);
void				*ft_memccpy(void *s, const void *d, int i, size_t len);
void				*ft_memmove(void *s, const void *d, size_t len);
void				*ft_memchr(const void *s, int i, size_t len);
int					ft_memcmp (const void *s, const void *d, size_t len);
size_t				ft_strlen(const char *s);
char				*ft_strcpy(char *s, const char *d);
char				*ft_strdup(const char *s);
char				*ft_strncpy(char *s, const char *d, size_t len);
char				*ft_strcat(char *s, const char *d);
char				*ft_strncat (char *s, const char *d, size_t len);
size_t				ft_strlcat(char *s, const char *d, size_t len);
char				*ft_strchr (const char *s, int i);
char				*ft_strrchr (const char *s, int i);
char				*ft_strstr(const char *s, const char *d);
char				*ft_strnstr(const char *s, const char *d, size_t len);
int					ft_strcmp(const char *s, const char *d);
int					ft_strncmp(const char *s, const char *d, size_t len);
int					ft_atoi(char *s);
int					ft_isalpha(int i);
int					ft_isdigit(int i);
int					ft_isalnum(int i);
int					ft_isascii(int i);
int					ft_isprint(int i);
int					ft_toupper(int i);
int					ft_tolower(int ch);
void				ft_memdel(void **s);
void				*ft_memalloc(size_t len);
char				*ft_strnew(size_t len);
void				ft_strdel(char **s);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *d));
void				ft_striteri(char *s, void (*f)(unsigned int, char *d));
char				*ft_strmap(char const *s, char (*f)(char d));
char				*ft_strmapi(char const *s, char(*f)(unsigned int, char));
int					ft_strequ(char const *s, char const *d);
int					ft_strnequ(char const *s, char const *d, size_t len);
char				*ft_strsub(char const *s, unsigned int i, size_t len);
char				*ft_strjoin(char const *s, char const *d);
char				*ft_strtrim(char const *s);
void				ft_putchar(char d);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
char				**ft_strsplit(char const *s, char d);
char				*ft_itoa(int i);
void				ft_putnbr_fd(int i, int j);
void				ft_putnbr(int i);
void				ft_putchar_fd(char c, int i);
void				ft_putstr_fd(char const *s, int i);
void				ft_putendl_fd(char const *s, int i);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_is_whitespace(char c);
long				ft_countw(char *str, char sep);
int					ft_sqrt(int nb);
int					power(int t, int k);
char				*ft_rot42(char *str);
char				*ft_strndup(const char *s1, size_t n);
size_t				ft_abs(int n);
int					get_next_line(int fd, char **line);
#endif
