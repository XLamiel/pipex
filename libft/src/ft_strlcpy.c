/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlamiel- <xlamiel-@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 20:01:07 by xlamiel-          #+#    #+#             */
/*   Updated: 2025/05/27 17:47:46 by xlamiel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

/*
int main(void)
{
    char buf[10];
    size_t result;
    
    // Test 1: Basic copy
    result = ft_strlcpy(buf, "hello", 10);
    printf("Test 1: buf = '%s', return %zu 
		(expected 'hello', 5)\n", buf, result);
    
    // Test 2: Exact fit
    result = ft_strlcpy(buf, "123456789", 10);
    printf("Test 2: buf = '%s', return %zu 
		(expected '123456789', 9)\n", buf, result);
    
    // Test 3: Truncation
    result = ft_strlcpy(buf, "1234567890", 10);
    printf("Test 3: buf = '%s', return %zu 
		(expected '123456789', 10)\n", buf, result);
    
    // Test 4: Size = 0
    char prev_content[10] = "previous";
    result = ft_strlcpy(prev_content, "hello", 0);
    printf("Test 4: buf = '%s', return %zu 
		(expected 'previous', 5)\n", prev_content, result);
    
    // Test 5: Minimum size (1)
    char min_buf[1];
    result = ft_strlcpy(min_buf, "hello", 1);
    printf("Test 5: buf[0] = %d, return %zu 
		(expected 0, 5)\n", min_buf[0], result);
    
    // Test 6: NULL dst
    result = ft_strlcpy(NULL, "hello", 10);
    printf("Test 6: return %zu 
		(expected 0)\n", result);
    
    // Test 7: NULL src
    result = ft_strlcpy(buf, NULL, 10);
    printf("Test 7: return %zu 
		(expected 0)\n", result);
    
    return (0);
}
*/
