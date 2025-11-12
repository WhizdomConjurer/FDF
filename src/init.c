/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: puzzlesanalytik <puzzlesanalytik@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:42:43 by puzzlesanal       #+#    #+#             */
/*   Updated: 2025/11/12 14:39:05 by puzzlesanal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_projektion	*init_projektion(uint32_t w, uint32_t h)
{
	t_projektion	*p;
	uint32_t		total;

	p = malloc(sizeof(t_projektion));
	if (!p)
		return (NULL);
	total = w * h;
	p->x = alloc_int_arr(total);
	p->y = alloc_int_arr(total);
	p->z = alloc_int_arr(total);
	p->color = alloc_uint_arr(total);
	if (!p->x || !p->y || !p->z || !p->color)
		return (free(p->x), free(p->y), free(p->z), free(p->color), free(p), NULL);
	init_projection_meta(p, w, h);
	return (p);
}


t_coords    *init_coords(int token_count)
{
    t_coords    *coords;

    coords = malloc(sizeof(t_coords));
    coords -> x = malloc(sizeof(int32_t) * token_count);
    coords -> y = malloc(sizeof(int32_t) * token_count);
    coords -> z = malloc(sizeof(int32_t) * token_count);
    coords -> color = malloc(sizeof(uint32_t) * token_count);
    coords -> width = 0;
    coords -> height = 0;
    coords -> size = 0;
    return (coords);
}

t_transformation	*init_transformation(void)
{
	t_transformation	*trans;

	trans = malloc(sizeof(t_transformation));
	if (!trans)
		return (NULL);
	trans->ofst_x = 0;
    trans->ofst_y = 0;
    trans->base_scl = SCALE;
	trans->scl_x = TILE_SIZE;
	trans->scl_y = TILE_SIZE;
	trans->scl_z = TILE_SIZE;
	trans->base_scl_x = trans->scl_x;
	trans->base_scl_y = trans->scl_y;
	trans->base_scl_z = trans->scl_z;
    trans->rot_x = ((54 % 360) + 360) % 360;
	trans->rot_y = ((0 % 360) + 360) % 360;
	trans->rot_z = ((35 % 360) + 360) % 360;
	return (trans);
}

t_lookup	*init_lookup(void)
{
	int32_t		idx;
	double		rad;
	t_lookup	*lookup;

	lookup = malloc(sizeof(t_lookup));
	if (!lookup)
		return (NULL);
	idx = 0;
	while (idx < 360)
	{
		rad = idx * M_PI / 180;
		lookup->cos[idx] = (int)(cos(rad) * SCALE + 0.5);
		lookup->sin[idx] = (int)(sin(rad) * SCALE + 0.5);
		idx++;
	}
	return (lookup);
}

t_engine	*init_fdf_engine(char *av)
{
	t_engine	*engine;

	engine = ft_calloc(1, sizeof(t_engine));
	if (!engine)
		return (NULL);
	engine -> mlx = mlx_init(WIDTH, HEIGHT, "FdF", true);
	if (!engine -> mlx)
		return (mlx_strerror(mlx_errno), free_engine(engine), NULL);
	engine -> img = mlx_new_image(engine->mlx, engine->mlx->width, engine->mlx->height);
	if (!engine -> img)
		return (mlx_strerror(mlx_errno), free_engine(engine), NULL);
    engine -> coords = parse_input(av);
    if (!engine -> coords)
        return (engine_free(engine), NULL);
    engine -> projektion = init_projektion(engine->coords->width, engine->coords->height);
    if (!engine->projektion)
        return(engine_free(engine), NULL);
    engine -> transformation = init_transformation();
    if (!engine->transformation)
        return (engine_free(engine), NULL);
    engine -> lookup = init_lookup();
    if (!engine->lookup)
        return (engine_free(engine), NULL);
    return (engine);
}

