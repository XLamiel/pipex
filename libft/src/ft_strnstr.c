/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:05:13 by xlamiel-          #+#    #+#             */
/*   Updated: 2025/05/27 17:58:07 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (i < len && big[i] != '\0')
	{
		j = 0;
		while (i + j < len && big[i + j] == little[j])
		{
			if (little[j + 1] == '\0')
				return ((char *)(big + i));
			j++;
		}
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>

int main(void)
{
	const char *big_str;
	const char *little_str;
	char *result;
	size_t test_len;
	
	/ Caso 1: Subcadena presente /
	big_str = "Buscando una aguja en un pajar";
	little_str = "aguja";
	test_len = 30;
	
	result = ft_strnstr(big_str, little_str, test_len);
	printf("Caso 1: %s\n", result ? "Encontrado" : "No encontrado");
	
	/ Caso 2: Subcadena no presente /
	little_str = "alfiler";
	result = ft_strnstr(big_str, little_str, test_len);
	printf("Caso 2: %s\n", result ? "Encontrado" : "No encontrado");
	
	/ Caso 3: Límite de búsqueda corto /
	test_len = 15;
	result = ft_strnstr(big_str, little_str, test_len);
	printf("Caso 3: %s\n", result ? "Encontrado" : "No encontrado");
	
	/ Caso 4: Cadena vacía /
	little_str = "";
	result = ft_strnstr(big_str, little_str, test_len);
	printf("Caso 4: %s\n", result ? "Encontrado" : "No encontrado");
	
	/ Caso 5: Punteros NULL /
	result = ft_strnstr(NULL, little_str, test_len);
	printf("Caso 5: %s\n", result ? "Encontrado" : "No encontrado");
	
	return 0;
}
*/
