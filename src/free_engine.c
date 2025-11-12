/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reriebsc <reriebsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:55:00 by puzzlesanal       #+#    #+#             */
/*   Updated: 2025/11/12 19:48:57 by reriebsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_token(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

static void	coords_free(t_engine *engine)
{
	if (engine->coords)
	{
		if (engine->coords->x)
			free(engine->coords->x);
		if (engine->coords->y)
			free(engine->coords->y);
		if (engine->coords->z)
			free(engine->coords->z);
		if (engine->coords->color)
			free(engine->coords->color);
		free(engine->coords);
	}
}

void	engine_free(t_engine *engine)
{
	if (engine->img)
		mlx_delete_image(engine->mlx, engine->img);
	if (engine->mlx)
		mlx_terminate(engine->mlx);
	coords_free(engine);
	if (engine->projektion)
	{
		if (engine->projektion->x)
			free(engine->projektion->x);
		if (engine->projektion->y)
			free(engine->projektion->y);
		if (engine->projektion->z)
			free(engine->projektion->z);
		if (engine->projektion->color)
			free(engine->projektion->color);
		free(engine->projektion);
	}
	if (engine->lookup)
		free(engine->lookup);
	if (engine->transformation)
		free(engine->transformation);
	if (engine)
		free(engine);
}
