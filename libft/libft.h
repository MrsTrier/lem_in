/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshelia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 11:08:22 by vshelia           #+#    #+#             */
/*   Updated: 2020/01/23 18:30:25 by vshelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdarg.h>

/*
** AVL tree
*/

typedef struct		s_avl_tree
{
	void				*content;
	unsigned int		height;
	struct s_avl_tree	*right;
	struct s_avl_tree	*left;
}					t_avl_tree;

t_avl_tree			*ft_avl_tree_new(void *content);
t_avl_tree			*ft_avl_left_rotate(t_avl_tree *node);
t_avl_tree			*ft_avl_right_rotate(t_avl_tree *node);
t_avl_tree			*ft_avl_tree_insert(t_avl_tree *node, void *content,
					int (*compare)(void *, void *));
t_avl_tree			*ft_avl_tree_search(t_avl_tree *node, void *content,
					int (*compare)(void *, void *));
void				ft_avl_tree_preorder(t_avl_tree *node, void (*f)(void *));
void				ft_avl_tree_inorder(t_avl_tree *node, void (*f)(void *));
void				ft_avl_tree_postorder(t_avl_tree *node, void (*f)(void *));

/*
** ft_printf
*/

typedef struct		s_format
{
	char		*flags;
	char		*width;
	char		*precision;
	char		*length;
	char		*type;
}					t_format;

int					ft_fprintf(int fd, const char *format, ...);
int					ft_printf(const char *format, ...);

int					parser(int fd, char *format, va_list arg);
char				*get_type(char **format);
char				*get_length(char **format);
char				*get_precision(char **format);
char				*get_width(char **format);
char				*get_flags(char **format);

int					convert_n_print(int fd, t_format *parse, va_list arg);
char				*operation_definer(t_format *parse, va_list arg);
int					handle_asterisk(t_format *parse, va_list arg);
void				free_asterisk(t_format *parse, int code);

char				*string_assignment(char *str);
char				*add_prefix(const char *prefix, char *source);

char				*prefix_attacher(t_format *parse, char *source);
char				*signed_integer_handler(t_format *parse, va_list arg);
char				*unsigned_integer_handler(t_format *parse, va_list arg,
						int base);
char				*str_upper(char *source);
char				*float_handler(t_format *parse, va_list arg);
int					rounder(char *fraction, int i);
char				*plus_one(char *str);

char				*apply_precision(t_format *parse, char *source);
char				*apply_width(t_format *parse, char *source);
char				*apply_flags(t_format *parse, char *source);
int					flag_exists(char *flags, char flag);
int					number_is_zero(const char *str);

char				*ft_ctoa(char ch);
char				*ft_lltoa(long long n);
char				*ft_ulltoa_base(unsigned long long n, int base);
char				*ft_ldtoa(long double f, char *precision);
unsigned long long	ft_atoull(const char *str);

void				free_both(void *ptr1, void *ptr2);
char				*replace_by_esc(char *string);
char				*ft_utfctoa(unsigned int ch);
char				*non_to_printable(char *str);

/*
** esc control sequences
*/

# define RESET        "\e[0m"

# define BOLD         "\e[1m"
# define DIM          "\e[2m"
# define UNDERSCORE   "\e[3m"
# define BLINK        "\e[4m"
# define REVERSE      "\e[5m"
# define HIDDEN       "\e[6m"

# define F_BLACK      "\e[30m"
# define F_RED        "\e[31m"
# define F_GREEN      "\e[32m"
# define F_YELLOW     "\e[33m"
# define F_BLUE       "\e[34m"
# define F_MAGENTA    "\e[35m"
# define F_CYAN       "\e[36m"
# define F_WHITE      "\e[37m"

# define B_BLACK      "\e[40m"
# define B_RED        "\e[41m"
# define B_GREEN      "\e[42m"
# define B_YELLOW     "\e[44m"
# define B_BLUE       "\e[44m"
# define B_MAGENTA    "\e[45m"
# define B_CYAN       "\e[46m"
# define B_WHITE      "\e[47m"

# define B_COLOR_1    "\e[48;5;1m"
# define B_COLOR_7    "\e[48;5;7m"
# define B_COLOR_9    "\e[48;5;9m"
# define B_COLOR_10   "\e[48;5;10m"
# define B_COLOR_11   "\e[48;5;11m"
# define B_COLOR_12   "\e[48;5;12m"
# define B_COLOR_15   "\e[48;5;15m"
# define B_COLOR_20   "\e[48;5;20m"
# define B_COLOR_22   "\e[48;5;22m"
# define B_COLOR_30   "\e[48;5;30m"
# define B_COLOR_40   "\e[48;5;40m"
# define B_COLOR_50   "\e[48;5;50m"
# define B_COLOR_57   "\e[48;5;57m"
# define B_COLOR_79   "\e[48;5;79m"
# define B_COLOR_81   "\e[48;5;81m"
# define B_COLOR_82   "\e[48;5;82m"
# define B_COLOR_90   "\e[48;5;90m"
# define B_COLOR_100  "\e[48;5;100m"
# define B_COLOR_124  "\e[48;5;124m"
# define B_COLOR_168  "\e[48;5;168m"
# define B_COLOR_180  "\e[48;5;180m"
# define B_COLOR_198  "\e[48;5;198m"
# define B_COLOR_202  "\e[48;5;202m"
# define B_COLOR_240  "\e[48;5;240m"
# define B_COLOR_250  "\e[48;5;250m"
# define B_COLOR_224  "\e[48;5;202m"

void				ft_putchar_esc(const char *esc, char ch);

/*
** get_next_line
*/

# define BUFF_SIZE 5000

typedef struct		s_fds
{
	int				fd;
	char			*buffer;
	struct s_fds	*next;
}					t_fds;

int					get_next_line(const int fd, char **line);
int					get_next_line_n(const int fd, char **line);

/*
** libft origin functions
*/

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_isdigit(int c);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isprint(int c);
int					ft_isascii(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
int					ft_atoi(const char *str);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_sqrt(int nb);
int					ft_isspace(int c);
void				*ft_realloc(void *ptr, size_t size, size_t new_size);
void				ft_str_toupper(char *str);
void				ft_str_tolower(char *str);

/*
** libft functions, added later (during work on other projects)
*/

int					ft_str_isnumber(const char *str);
long long			ft_atoll(const char *str);
void				ft_error(const char *msg);
void				ft_free_strsplit(char **str_array);

#endif
