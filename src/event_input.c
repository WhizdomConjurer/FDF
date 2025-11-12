/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reriebsc <reriebsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:38:29 by puzzlesanal       #+#    #+#             */
/*   Updated: 2025/11/12 19:18:26 by reriebsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	handle_translation(t_engine *e)
{
	if (mlx_is_key_down(e->mlx, MLX_KEY_RIGHT))
		translate_and_draw(e, X_POS);
	else if (mlx_is_key_down(e->mlx, MLX_KEY_LEFT))
		translate_and_draw(e, X_NEG);
	else if (mlx_is_key_down(e->mlx, MLX_KEY_UP))
		translate_and_draw(e, Y_NEG);
	else if (mlx_is_key_down(e->mlx, MLX_KEY_DOWN))
		translate_and_draw(e, Y_POS);
}

static void	handle_rotation(t_engine *e)
{
	if (mlx_is_key_down(e->mlx, MLX_KEY_Q))
		rotate_and_draw(e, X_POS);
	else if (mlx_is_key_down(e->mlx, MLX_KEY_A))
		rotate_and_draw(e, X_NEG);
	else if (mlx_is_key_down(e->mlx, MLX_KEY_W))
		rotate_and_draw(e, Y_POS);
	else if (mlx_is_key_down(e->mlx, MLX_KEY_S))
		rotate_and_draw(e, Y_NEG);
	else if (mlx_is_key_down(e->mlx, MLX_KEY_E))
		rotate_and_draw(e, Z_POS);
	else if (mlx_is_key_down(e->mlx, MLX_KEY_D))
		rotate_and_draw(e, Z_NEG);
}

static void	handle_scaling(t_engine *e)
{
	if (mlx_is_key_down(e->mlx, MLX_KEY_R))
		scale_and_draw(e, Z_POS);
	else if (mlx_is_key_down(e->mlx, MLX_KEY_F))
		scale_and_draw(e, Z_NEG);
}

void	handle_input(t_engine *e)
{
	if (mlx_is_key_down(e->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(e->mlx);
	if (mlx_is_key_down(e->mlx, MLX_KEY_SPACE))
		reset_and_draw(e);
	else
	{
		handle_translation(e);
		handle_rotation(e);
		handle_scaling(e);
	}
}
