/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 20:39:02 by xlamiel-          #+#    #+#             */
/*   Updated: 2025/05/27 20:59:55 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <stdlib.h>  // Asegúrate de incluir malloc

char	*ft_strdup(const char *s)
{
	char	*new_str;
	size_t	length;
	size_t	i;

	length = ft_strlen(s);
	new_str = (char *)malloc(sizeof(char) * (length + 1));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		new_str[i] = s[i];
		i++;
	}
	new_str[length] = '\0';
	return (new_str);
}
