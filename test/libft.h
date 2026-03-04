/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:27:12 by pedrohe3          #+#    #+#             */
/*   Updated: 2026/02/19 19:42:19 by pedrohe3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>


// Part 1
int				ft_isalpha(int value);
int				ft_isdigit(int value);
int				ft_isalnum(int value);
int				ft_isascii(int value);
int				ft_isprint(int value);
size_t			ft_strlen(const char *str);
void			*ft_memset(void *ptr, int x, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t count);
void			*ft_memmove(void *dest, const void *src, size_t n);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
unsigned int	ft_strlcat(char *dst, const char *src, unsigned int size);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strchr(const char *str, int c);
char			*ft_strrchr(const char *str, int c);
int				ft_strncmp(char *s1, char *s2, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strnstr(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
void			*ft_calloc(size_t nmemb, size_t size);
char			*ft_strdup(const char *s);

// Part 2
char			*ft_substr(char const *s, unsigned int start,\
		size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

// Part 3 - Bonus
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),\
		void (*del)(void *));

// Printf
int				ft_printf(const char *format, ...);
int				ft_putchar_pf(char c, int *count);
int				ft_putstr_pf(char *s, int *count);
int				ft_putptr_pf(long ptr, int *count);
int				ft_putnbr_base_pf(long nbr, char *base, int *count);
int				ft_puthex_pf(unsigned int nbr, char hcase, int *count);
int				ft_putnbr_pf(int nbr, int *count);
int				ft_putuint_pf(unsigned int nbr, int *count);

#endif
