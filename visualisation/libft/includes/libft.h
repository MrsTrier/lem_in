/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 19:29:25 by mcanhand          #+#    #+#             */
/*   Updated: 2019/09/19 18:01:48 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "get_next_line.h"

typedef enum
{
	false,
	true
}	t_bool;

typedef struct		s_list
{
	char			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_arr
{
	int				content;
	struct s_arr	*next;
}					t_arr;

void				*ft_memalloc(size_t size);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_striter(char *s, void (*f)(char *));
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putnbr(int n);
void				ft_strdel(char **as);
void				ft_memdel(void **ap);
void				ft_bzero(void *s, size_t n);
void				ft_strclr(char *s);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				free_arr(char **arr);
int					ft_atoi(const char *str);
int					ft_isdigit(int c);
int					ft_isascii(int c);
int					ft_isalpha(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isprint(int c);
int					ft_isalnum(int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_any(char **tab, int (*f)(char*));
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strdup(char *src);
char				*ft_strcat(char *dest, const char *src);
char				*ft_itoa(int n);
char				*ft_reverse(char *s);
char				*ft_strnew(size_t size);
char				*strchr(const char *s, int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strtrim(char *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *str, const char *to_find);
char				*ft_strnstr(const char *str, char *to_find,
														size_t len);
char				*ft_strncat(char *dest, const char *src, size_t nb);
char				*ft_strncpy(char *dst, const char *src, size_t len);
size_t				ft_strlen(char *str);
size_t				ft_strlcat(char *dst, char *src, size_t size);
t_list				*ft_lstnew(char *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_create_elem(void *data);
t_list				*ft_list_at(t_list *begin_list, unsigned int nbr);
char				*ft_itoa_base(long long int n, int base, int uppercase);
char				*ft_itoa_base_hex_long(unsigned long long n, int base,
															int uppercase);
char				*fill_with_chars(int num, char c);
void				*ft_realloc(void *mem, size_t old_size, size_t new_size);
void				ft_push_back(t_list **start, t_list *new);
char				*ft_strappend(char *s1, char *s2);
char				*ft_lst_to_str(t_list *lst);
int					create_node(void *str, size_t len, t_list **lst);
t_bool				is_int(const char *str);
int					get_next_line(const int fd, char **line);
int					ft_count_if(char **tab, t_bool (*f)(const char*));

#endif
