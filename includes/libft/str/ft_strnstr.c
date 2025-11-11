/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: puzzlesanalytik <puzzlesanalytik@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:25:24 by puzzlesanal       #+#    #+#             */
/*   Updated: 2025/11/10 13:25:27 by puzzlesanal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *haystack, const char *needl, size_t len)
{
	size_t	len2;

	if (*needl == '\0')
		return ((char *)haystack);
	len2 = ft_strlen(needl);
	while (*haystack != '\0' && len-- >= len2)
	{
		if (*haystack == *needl && ft_memcmp(haystack, needl, len2) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}