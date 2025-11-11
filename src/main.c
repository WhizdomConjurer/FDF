/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: puzzlesanalytik <puzzlesanalytik@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:42:45 by puzzlesanal       #+#    #+#             */
/*   Updated: 2025/11/11 13:39:19 by puzzlesanal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int32_t	main(int ac, char **av)
{
	t_engine	*engin;

	if (2 != ac)
		return (EXIT_FAILURE);
	engin = init_ctx(av[1]);
	if (!engin)
		return (EXIT_FAILURE);
	if (mlx_image_to_window(engin->mlx, engin->img, 0, 0) == -1)
		return (mlx_strerror(mlx_errno), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
