/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaquet <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 12:23:01 by nhaquet           #+#    #+#             */
/*   Updated: 2018/03/23 15:48:28 by nhaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFT_H
# define FT_LIBFT_H
# include <string.h>
# include <unistd.h>
# include "get_next_line.h"

void	ft_putchar(char c);
void	ft_putstr(char const *s);
void	ft_putnbr(int n);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *str, int c, size_t num);
void	ft_bzero(void *str, size_t num);
char	*ft_strcpy(char *s1, const char *s2);
char	*ft_strncpy(char *str1, const char *str2, size_t num);
char	*ft_strdup(const char *s1);
void	*ft_memcpy(void *s1, const void *s2, size_t n);
void	*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void	*ft_memmove(void *s1, const void *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strncat(char *s1, const char *s2, size_t n);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strstr(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnew(size_t size);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	**ft_strsplit(const char *s, const char c);
double	ft_sqrt(double num);
void	*ft_realloc(void *mem, size_t new_size);
char	*ft_strdup2(const char *s1);
int		get_next_line(int fd, char **line);
int		ft_intlen(int nbr);
void	ft_freetab(void **tab);
char	*ft_itoa(int n);
#endif
