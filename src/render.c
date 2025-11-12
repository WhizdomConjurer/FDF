/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: puzzlesanalytik <puzzlesanalytik@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:42:50 by puzzlesanal       #+#    #+#             */
/*   Updated: 2025/11/12 17:04:05 by puzzlesanal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	init_line_calc(t_line_calc *c, t_coord *start,
	t_coord *end, enum e_line_ori ori)
{
	c->start = start;
	c->end = end;
	c->ori = ori;
	if (ori == VERT)
		c->d2 = end->y - start->y;
	else
		c->d2 = end->x - start->x;
	if (ori == VERT)
		c->d1 = end->x - start->x;
	else
		c->d1 = end->y - start->y;
	if (c->d1 < 0)
		c->dir = -1;
	else
		c->dir = 1;
	c->d1 *= c->dir;
	if (ori == VERT)
		c->t = start->x;
	else
		start->y;
	c->p = 2 * c->d1 - c->d2;
	c->i = 0;
}

static void	draw_pixel(t_line_calc *c, mlx_image_t *img)
{
	uint32_t	col;
	int32_t		x;
	int32_t		y;

	col = interpolate_colors(c->start->color, c->end->color,
			c->d2, c->i);
	if (c->ori == VERT)
		x = c->t;
	else
		x = c->start->x + c->i;
	if (c->ori == VERT)
		y = c->start->y + c->i;
	else
		c->t;
	if (x >= 0 && x < (int32_t)img->width
		&& y >= 0 && y < (int32_t)img->height)
		mlx_put_pixel(img, x, y, col);
}

static void	step_line(t_line_calc *c)
{
	if (c->p >= 0)
	{
		c->t += c->dir;
		c->p -= 2 * c->d2;
	}
	c->p += 2 * c->d1;
	c->i++;
}

static void	draw_calc(t_line_calc *c, mlx_image_t *img)
{
	while (c->i < c->d2)
	{
		draw_pixel(c, img);
		step_line(c);
	}
}

void	draw_line(t_coord *start, t_coord *end, mlx_image_t *img)
{
	t_line_calc		calc;
	enum e_line_ori	ori;

	if (ft_abs(start->x - end->x) > ft_abs(start->y - end->y))
		ori = HORZ;
	else
		ori = VERT;
	if ((ori == HORZ && start->x > end->x)
		|| (ori == VERT && start->y > end->y))
		swap_coords(&start, &end);
	init_line_calc(&calc, start, end, ori);
	if (calc.d2 == 0)
		return ;
	draw_calc(&calc, img);
}
