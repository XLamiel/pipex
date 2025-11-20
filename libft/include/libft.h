/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:51:57 by xlamiel-          #+#    #+#             */
/*   Updated: 2025/09/10 21:53:15 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdint.h>
# include <limits.h>
# include <unistd.h>

// ft_satoi.c
# ifndef SATOI_SUCCESS
#  define SATOI_SUCCESS 0
# endif

# ifndef SATOI_OVERFLOW 
#  define SATOI_OVERFLOW 1
# endif

# ifndef SATOI_INVALID_CHAR
#  define SATOI_INVALID_CHAR 2
# endif

# ifndef SATOI_NO_DIGITS 
#  define SATOI_NO_DIGITS 3
# endif

# ifndef SATOI_EMPTY_STRING 
#  define SATOI_EMPTY_STRING 4
# endif

// ft_satol.c
# ifndef SATOL_SUCCESS
#  define SATOL_SUCCESS 0
# endif

# ifndef SATOL_OVERFLOW 
#  define SATOL_OVERFLOW 1
# endif

# ifndef SATOL_INVALID_CHAR
#  define SATOL_INVALID_CHAR 2
# endif

# ifndef SATOL_NO_DIGITS 
#  define SATOL_NO_DIGITS 3
# endif

# ifndef SATOL_EMPTY_STRING 
#  define SATOL_EMPTY_STRING 4
# endif

typedef struct s_satoi
{
	int	value;
	int	error;
}	t_satoi;

typedef struct s_satol
{
	long	value;
	int		error;
}	t_satol;

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_isspace(char c);
char	*ft_itoa(int n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_toupper(int c);
int		ft_tolower(int c);

/* Main function prototype */
int		ft_printf(const char *format, ...);

/* Handler functions prototypes */
int		ft_handle_char(va_list args);
int		ft_handle_string(va_list args);
int		ft_handle_pointer(va_list args);
int		ft_handle_number(va_list args, int base, int uppercase);
int		ft_handle_unsigned(va_list args, int base, int uppercase);
int		ft_handle_format(const char **format, va_list args);

/* Utility functions prototypes */
char	*ft_itoa_base(unsigned long n, int base, int uppercase);

/* Safe atoi  ft_satoi.c*/
t_satoi	ft_satoi(const char *str);
t_satoi	i_validate_trailing_chars(const char *str, size_t i, t_satoi result);

/* Safe atoi  ft_satoi_core.c*/
int		i_process_next_digit(int *value, int digit_val, int sign);
int		i_handle_overflow(t_satoi *result, int sign, size_t *i,
			const char *str);
int		i_process_digit_loop(const char *str, size_t *i,
			t_satoi *result, int sign);
int		i_convert_digits(const char *str, size_t *i,
			t_satoi *result, int sign);
t_satoi	i_parse_digits(const char *str, size_t *i, int sign);

/* Safe atoi  ft_satoi_utils.c*/
size_t	i_skip_spaces(const char *str);
int		i_process_sign(const char *str, size_t *i);
int		i_check_overflow_positive(int value, int digit_val);
int		i_check_overflow_negative(int value, int digit_val);

// Safe atol  ft_satol.c
t_satol	ft_satol(const char *str);
t_satol	l_validate_trailing_chars(const char *str, size_t i, t_satol result);

// Safe atol  ft_satol_core.c
int		l_process_next_digit(long *value, int digit_val, long sign);
int		l_handle_overflow(t_satol *result, long sign, size_t *i,
			const char *str);
int		l_process_digit_loop(const char *str, size_t *i, t_satol *result,
			long sign);
int		l_convert_digits(const char *str, size_t *i, t_satol *result,
			long sign);
t_satol	l_parse_digits(const char *str, size_t *i, long sign);

// Safe atol  ft_satol_utils.c
size_t	l_skip_spaces(const char *str);
long	l_process_sign(const char *str, size_t *i);
int		l_check_overflow_positive(long value, int digit_val);
int		l_check_overflow_negative(long value, int digit_val);

#endif

/*
unistd.h
	write
	read
stdlib.h
	malloc
	free
	NULL

stddef.h
	size_t

stdint.h
	INTMAX_MIN
	INTMAX_MAX
limits.h
	INT_MAX
	INT_MIN
*/
