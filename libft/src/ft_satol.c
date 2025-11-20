/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_satol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 20:17:55 by xlamiel-          #+#    #+#             */
/*   Updated: 2025/09/10 21:52:43 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

/* libft.h

// Definición de códigos de error
#define SATOL_SUCCESS 0
#define SATOL_OVERFLOW 1
#define SATOL_INVALID_CHAR 2
#define SATOL_NO_DIGITS 3
#define SATOL_EMPTY_STRING 4

// error 0, success 1
typedef struct	s_satol
{
	long	value;
	int		error;
} t_satol;

*/

t_satol	l_validate_trailing_chars(const char *str, size_t i, t_satol result)
{
	if (str[i] != '\0')
	{
		result.error = SATOL_INVALID_CHAR;
		result.value = 0;
	}
	return (result);
}

t_satol	ft_satol(const char *str)
{
	t_satol	result;
	size_t	i;
	long	sign;

	if (!str || str[0] == '\0')
		return ((t_satol){.value = 0, .error = SATOL_EMPTY_STRING});
	i = l_skip_spaces(str);
	sign = l_process_sign(str, &i);
	if (!ft_isdigit(str[i]))
		return ((t_satol){.value = 0, .error = SATOL_NO_DIGITS});
	result = l_parse_digits(str, &i, sign);
	if (result.error != SATOL_SUCCESS)
		return (result);
	return (l_validate_trailing_chars(str, i, result));
}
