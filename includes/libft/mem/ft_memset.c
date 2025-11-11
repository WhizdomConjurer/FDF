/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: puzzlesanalytik <puzzlesanalytik@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:14:29 by puzzlesanal       #+#    #+#             */
/*   Updated: 2025/11/10 13:14:32 by puzzlesanal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memset(void *ptr, int value, size_t len)
{
	unsigned char	*c;
	unsigned int	x;

	c = (unsigned char *)ptr;
	x = 0;
	while (x < len)
	{
		c[x++] = value;
	}
	ptr = (void *)c;
	return (ptr);
}