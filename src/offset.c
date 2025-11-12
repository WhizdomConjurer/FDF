/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: puzzlesanalytik <puzzlesanalytik@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:53:18 by puzzlesanal       #+#    #+#             */
/*   Updated: 2025/11/12 15:20:57 by puzzlesanal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int32_t	get_mesh_width(t_projektion *p)
{
	return (p->max_prox - p->min_prox);
}

static int32_t	get_mesh_height(t_projektion *p)
{
	return (p->max_proy - p->min_proy);
}

void	get_offset(t_engine *e)
{
	t_projektion	*p;
	int32_t			w;
	int32_t			h;

	p = e->projektion;
	w = get_mesh_width(p);
	h = get_mesh_height(p);
	p->offset_x = ((int32_t)e->img->width - w) / 2 - p->min_prox;
	p->offset_y = ((int32_t)e->img->height - h) / 2 - p->min_proy;
	p->offset_x += e->transformation->ofst_x;
	p->offset_y += e->transformation->ofst_y;
}
