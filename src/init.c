/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: puzzlesanalytik <puzzlesanalytik@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:42:43 by puzzlesanal       #+#    #+#             */
/*   Updated: 2025/11/11 13:36:48 by puzzlesanal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_engine	*init_ctx(char *av)
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
    
}