/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrodr < marcrodr@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 22:10:50 by marcrodr          #+#    #+#             */
/*   Updated: 2022/02/14 22:10:53 by marcrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>

# define DECIMAL	"0123456789"
# define HEXALOWER	"0123456789abcdef"
# define HEXAUPPER	"0123456789ABCDEF"
# define BUFFER_SIZE	32

int				ft_atoi(const char *str);
int				ft_isalnum(int n);
int				ft_isalpha(int n);
int				ft_isascii(int n);
int				ft_isdigit(int arg);
int				ft_isprint(int n);
int				ft_tolower(int n);
int				ft_toupper(int n);
int				ft_memcmp(const void *str1, const void *str2, size_t n);
int				ft_strncmp(const char *str1, const char *str2, size_t n);
int				ft_printf(const char *str, ...);
int				print_c(char *str, int arg);
int				print_s(char *str, char *arg);
int				print_d(char *str, int arg);
int				print_x(char *str, unsigned long int arg);
int				print_percent(char *str);
int				ft_hexstrtoi(char *hex);
int				ft_isspace(char c);

void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *str, int c, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);

size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *str);

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strnstr(const char *str, const char *to_find, size_t n);
char			*ft_strrchr(const char *str, int c);
char			*ft_strchr(const char *str, int c);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_itoa(int n);
char			*get_next_line(int fd);
char			*ft_ullitoa_base(unsigned long long int n, char *base);
char			*ft_ftoa(float number);

char			*ft_strdup(const char *s1);
void			*ft_calloc(size_t nitems, size_t size);

void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_free_split(char **split);

char			*ft_strncpy(char *dest, char *src, unsigned int n);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			**ft_split(char const *s, char c);

#endif
