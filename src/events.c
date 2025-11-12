/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: puzzlesanalytik <puzzlesanalytik@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:42:40 by puzzlesanal       #+#    #+#             */
/*   Updated: 2025/11/12 16:29:20 by puzzlesanal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	apply_zoom(t_transformation *t, double ydelta)
{
	if (ydelta > 0)
		t->base_scl = (t->base_scl * 1100) / SCALE;
	else if (ydelta < 0)
		t->base_scl = (t->base_scl * 900) / SCALE;
}

static void	update_scaling(t_transformation *t)
{
	t->scl_x = (t->base_scl_x * t->base_scl) / SCALE;
	t->scl_y = (t->base_scl_y * t->base_scl) / SCALE;
	t->scl_z = (t->base_scl_z * t->base_scl) / SCALE;
	if (t->scl_x < 1)
		t->scl_x = 1;
	if (t->scl_y < 1)
		t->scl_y = 1;
	if (t->scl_z < 1)
		t->scl_z = 1;
}

void	ft_scroll_hook(double xdelta, double ydelta, void *param)
{
	t_engine			*e;
	t_transformation	*t;

	(void)xdelta;
	e = param;
	t = e->transformation;
	apply_zoom(t, ydelta);
	update_scaling(t);
	draw(e);
}

void	ft_resize_hook(int32_t w, int32_t h, void *param)
{
	t_engine	*e;

	e = param;
	mlx_resize_image(e->img, (uint32_t)w, (uint32_t)h);
	fill_img(e, BACKGROUND);
	draw(e);
}

void	ft_hook(void *param)
{
	handle_input((t_engine *)param);
}
