/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reriebsc <reriebsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:53:21 by puzzlesanal       #+#    #+#             */
/*   Updated: 2025/11/12 21:44:18 by reriebsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	fill_img_column(mlx_image_t *img, uint32_t y, uint32_t color)
{
	uint32_t	x;

	x = 0;
	while (x < img->width)
	{
		mlx_put_pixel(img, x, y, color);
		x++;
	}
}

void	fill_img(t_engine *engine, uint32_t color)
{
	uint32_t	y;

	y = 0;
	while (y < engine->img->height)
	{
		fill_img_column(engine->img, y, color);
		y++;
	}
}

static void	set_point(t_engine *e, t_coord *pt, int32_t idx)
{
	pt->x = e->projektion->x[idx] + e->projektion->offset_x;
	pt->y = e->projektion->y[idx] + e->projektion->offset_y;
	pt->color = e->coords->color[idx];
}

static void	draw_projection_lines(t_engine *e, int32_t idx)
{
	t_coord			start;
	t_coord			end;
	t_projektion	*p;

	p = e->projektion;
	set_point(e, &start, idx);
	if ((idx + 1 < e->coords->size) && ((idx + 1) % p->width))
	{
		set_point(e, &end, idx + 1);
		draw_line(&start, &end, e->img);
	}
	if (idx + p->width < e->coords->size)
	{
		set_point(e, &end, idx + p->width);
		draw_line(&start, &end, e->img);
	}
}

void	draw(t_engine *e)
{
	int32_t	i;

	fill_img(e, 255);
	project(e);
	get_offset(e);
	i = 0;
	while (i < e->coords->size)
	{
		draw_projection_lines(e, i);
		i++;
	}
}
