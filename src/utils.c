/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: puzzlesanalytik <puzzlesanalytik@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:42:56 by puzzlesanal       #+#    #+#             */
/*   Updated: 2025/11/12 14:06:01 by puzzlesanal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int32_t	*alloc_int_arr(uint32_t size)
{
	return (int32_t *)malloc(sizeof(int32_t) * size);
}

uint32_t	*alloc_uint_arr(uint32_t size)
{
	return (uint32_t *)malloc(sizeof(uint32_t) * size);
}

void	init_projection_meta(t_projektion *p, uint32_t w, uint32_t h)
{
	p->width = w;
	p->heigth = h;
	p->offset_x = 0;
	p->offset_y = 0;
	p->idx = 0;
	p->max_prox = -2147483648;
	p->min_prox = 2147483647;
	p->max_proy = -2147483648;
	p->min_proy = 2147483647;
}
