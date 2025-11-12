/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: puzzlesanalytik <puzzlesanalytik@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:22:58 by puzzlesanal       #+#    #+#             */
/*   Updated: 2025/11/12 16:24:53 by puzzlesanal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>
#include "../includes/fdf.h"

uint32_t	interpolate_component(uint32_t c1, uint32_t c2,
		uint32_t max, uint32_t t)
{
	return ((c1 * (max - t) + c2 * t) / max);
}

uint32_t	interpolate_colors(uint32_t c1, uint32_t c2,
		uint32_t max, uint32_t t)
{
	uint32_t	*col1;
	uint32_t	*col2;
	uint32_t	rgba;

	col1 = get_color(c1);
	col2 = get_color(c2);
	if (!col1 || !col2)
		return (0);
	rgba = get_rgba(
			interpolate_component(col1[0], col2[0], max, t),
			interpolate_component(col1[1], col2[1], max, t),
			interpolate_component(col1[2], col2[2], max, t),
			interpolate_component(col1[3], col2[3], max, t));
	free(col1);
	free(col2);
	return (rgba);
}

int	hex_char_to_int(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	return (0);
}

uint32_t	convert_color_loop(char *str)
{
	uint32_t	out;
	uint32_t	i;

	i = 0;
	out = 0;
	while (str[i])
	{
		out = (out * 16) + hex_char_to_int(str[i]);
		i++;
	}
	return (out);
}

uint32_t	convert_color(char *str)
{
	if (!str)
		return (FOREGROUND);
	return (convert_color_loop(str + 2));
}
