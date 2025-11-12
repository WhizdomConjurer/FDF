/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coler_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: puzzlesanalytik <puzzlesanalytik@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:20:09 by puzzlesanal       #+#    #+#             */
/*   Updated: 2025/11/12 16:58:40 by puzzlesanal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>
#include "../includes/fdf.h"

int32_t	ft_abs(int32_t num)
{
	int32_t	x;

	x = num - 1;
	if (num < 0)
		x = x * num;
	else
		return (num);
	return (x);
}

uint32_t	get_rgba(uint32_t r, uint32_t g, uint32_t b, uint32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

uint32_t	*get_color(uint32_t color)
{
	uint32_t	*arr;

	arr = malloc(4 * sizeof(uint32_t));
	if (!arr)
		return (NULL);
	arr[0] = color >> 24;
	arr[1] = (color >> 16) & 0xFF;
	arr[2] = (color >> 8) & 0xFF;
	arr[3] = color & 0xFF;
	return (arr);
}
