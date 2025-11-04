/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_satoi.c                                         :+:      :+:    :+:   */
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
#define SATOI_SUCCESS 0
#define SATOI_OVERFLOW 1
#define SATOI_INVALID_CHAR 2
#define SATOI_NO_DIGITS 3
#define SATOI_EMPTY_STRING 4

typedef struct	s_satoi
{
	int	value;
	int	error;
} t_satoi;

*/

t_satoi	i_validate_trailing_chars(const char *str, size_t i, t_satoi result)
{
	if (str[i] != '\0')
	{
		result.error = SATOI_INVALID_CHAR;
		result.value = 0;
	}
	return (result);
}

t_satoi	ft_satoi(const char *str)
{
	t_satoi	result;
	size_t	i;
	int		sign;

	if (!str || str[0] == '\0')
		return ((t_satoi){.value = 0, .error = SATOI_EMPTY_STRING});
	i = i_skip_spaces(str);
	sign = i_process_sign(str, &i);
	if (!ft_isdigit(str[i]))
		return ((t_satoi){.value = 0, .error = SATOI_NO_DIGITS});
	result = i_parse_digits(str, &i, sign);
	if (result.error != SATOI_SUCCESS)
		return (result);
	return (i_validate_trailing_chars(str, i, result));
}
