/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:43:04 by mstrauss          #+#    #+#             */
/*   Updated: 2024/09/05 12:54:17 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// LIBFT.H
#ifndef LIBFT_H
# define LIBFT_H
// EXTERNAL
# include <errno.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdbool.h>

ssize_t				write(int fd, const void *buf, size_t count);

// ############################# STRING HANDLING ##############################
int					ft_atoi(const char *str);
float				ft_atof(const char *str);
char				*ft_itoa(int n);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t count, size_t size);
int					ft_isalnum(int c);
int					ft_isalpha(int num);
int					ft_isascii(int c);
int					ft_isdigit(int num);
int					ft_isprint(int c);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strdup(const char *s1);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
int					ft_strlen(const char *s);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				**ft_split(char const *s, char c);

// ##############################  LINKED LISTS  ##############################
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

// #############################  GET NEXT LINE  #############################
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char				*get_next_line(int fd, bool finished);
char				*ft_strjoin_gl(char *s1, char *s2);
int					ft_strchr_gl(const char *s, char c);
size_t				ft_strlen_gl(const char *c);
void				ft_bzero_gl(void *s, size_t n);
void				*ft_calloc_gl(size_t count, size_t size);

#endif