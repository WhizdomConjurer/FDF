/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: puzzlesanalytik <puzzlesanalytik@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:42:45 by puzzlesanal       #+#    #+#             */
/*   Updated: 2025/11/12 16:30:01 by puzzlesanal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int32_t	main(int ac, char **av)
{
	t_engine	*engin;

	if (2 != ac)
		return (EXIT_FAILURE);
	engin = init_fdf_engine(av[1]);
	if (!engin)
		return (EXIT_FAILURE);
	if (mlx_image_to_window(engin->mlx, engin->img, 0, 0) == -1)
		return (EXIT_FAILURE);
	drawing(engin);
	mlx_loop_hook(engin->mlx, ft_hook, engin);
	mlx_resize_hook(engin->mlx, &ft_resize_hook, engin);
	mlx_scroll_hook(engin->mlx, &ft_scroll_hook, engin);
	mlx_loop(engin->mlx);
	return (engine_free(engin), EXIT_SUCCESS);
}
