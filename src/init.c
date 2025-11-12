/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: puzzlesanalytik <puzzlesanalytik@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:42:43 by puzzlesanal       #+#    #+#             */
/*   Updated: 2025/11/12 14:06:08 by puzzlesanal      ###   ########.fr       */
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
    
}

