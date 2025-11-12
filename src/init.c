/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: puzzlesanalytik <puzzlesanalytik@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:42:43 by puzzlesanal       #+#    #+#             */
/*   Updated: 2025/11/12 13:24:55 by puzzlesanal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
	engine->mlx = mlx_init(WIDTH, HEIGHT, "FdF", true);
	if (!engine->mlx)
		return (mlx_strerror(mlx_errno), free_engine(engine), NULL);
	engine->img = mlx_new_image(engine->mlx, engine->mlx->width, engine->mlx->height);
	if (!engine->img)
		return (mlx_strerror(mlx_errno), free_engine(engine), NULL);
    engine->coords = parse_input(av);
}

