/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projektion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reriebsc <reriebsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:50:29 by puzzlesanal       #+#    #+#             */
/*   Updated: 2025/11/12 20:25:20 by reriebsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	apply_transformations(t_engine *e, int32_t i)
{
	t_coords			*c;
	t_projektion		*p;
	t_transformation	*t;

	c = e->coords;
	p = e->projektion;
	t = e->transformation;
	p->x[i] = c->x[i] * t->scl_x;
	p->y[i] = c->y[i] * t->scl_y;
	p->z[i] = c->z[i] * t->scl_z;
}

static void	rotate_x(t_engine *e, int32_t idx)
{
	int64_t	sin;
	int64_t	cos;
	int64_t	tmp[2];

	sin = e->lookup->sin[e->transformation->rot_x];
	cos = e->lookup->cos[e->transformation->rot_x];
	tmp[0] = (cos * e->projektion->y[idx] - sin * e->projektion->z[idx])
		/ SCALE;
	tmp[1] = (sin * e->projektion->y[idx] + cos * e->projektion->z[idx])
		/ SCALE;
	e->projektion->y[idx] = tmp[0];
	e->projektion->z[idx] = tmp[1];
}

static void	rotate_y(t_engine *e, int32_t idx)
{
	int64_t	sin;
	int64_t	cos;
	int64_t	tmp[2];

	sin = e->lookup->sin[e->transformation->rot_y];
	cos = e->lookup->cos[e->transformation->rot_y];
	tmp[0] = (cos * e->projektion->x[idx] + sin * e->projektion->z[idx])
		/ SCALE;
	tmp[1] = (cos * e->projektion->z[idx] - sin * e->projektion->y[idx])
		/ SCALE;
	e->projektion->x[idx] = tmp[0];
	e->projektion->z[idx] = tmp[1];
}

static void	rotate_z(t_engine *e, int32_t idx)
{
	int64_t	sin;
	int64_t	cos;
	int64_t	tmp[2];

	sin = e->lookup->sin[e->transformation->rot_z];
	cos = e->lookup->cos[e->transformation->rot_z];
	tmp[0] = (cos * e->projektion->x[idx] - sin * e->projektion->y[idx])
		/ SCALE;
	tmp[1] = (sin * e->projektion->x[idx] + cos * e->projektion->y[idx])
		/ SCALE;
	e->projektion->x[idx] = tmp[0];
	e->projektion->y[idx] = tmp[1];
}

void	project(t_engine *e)
{
	int32_t	i;
	int32_t	total;

	init_projection_meta(e->projektion, WIDTH, HEIGHT);
	total = e->coords->width * e->coords->height;
	i = 0;
	while (i < total)
	{
		e->projektion->idx = i;
		apply_transformations(e, i);
		rotate_x(e, i);
		rotate_y(e, i);
		rotate_z(e, i);
		update_bounds(e->projektion, i);
		i++;
	}
}
