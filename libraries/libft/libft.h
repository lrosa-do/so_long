/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosa-do <lrosa-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 09:40:09 by lrosa-do          #+#    #+#             */
/*   Updated: 2022/06/04 16:16:21 by lrosa-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

int		ft_putchar(char c);
int		ft_print_str(char *str);
int		ft_print_int(int nb);
int		ft_print_uint(unsigned int n);
int		ft_print_ptr(unsigned long long ptr);
int		ft_print_hex(unsigned int num, const char format);
int		ft_printf(const char *format, ...);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memset(void *dest, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_malloc(size_t count);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
char	*ft_strrchr(const char *str, int c);
char	*ft_strchr(const char *s, int c);
int		ft_strpos(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
#endif
