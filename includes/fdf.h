/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: puzzlesanalytik <puzzlesanalytik@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:15:38 by puzzlesanal       #+#    #+#             */
/*   Updated: 2025/11/11 13:38:19 by puzzlesanal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 1280
# define HEIGHT 960

//#################################################
//#########structs
//##################################################

enum				e_line_ori
{
	VERT = 0,
	HORZ
};

enum				e_rot_dir
{
	X_POS = 0,
	X_NEG,
	Y_POS,
	Y_NEG,
	Z_POS,
	Z_NEG
};

typedef struct s_line_calc
{
	struct s_point	*start;
	struct s_point	*end;
	enum e_line_ori	ori;
	int32_t			dir;
	int32_t			i;
	int32_t			t;
	int32_t			d1;
	int32_t			d2;
	int32_t			p;
}					t_line_calc;

typedef struct s_coord
{
	int32_t			x;
	int32_t			y;
	int32_t			z;
	uint32_t		color;
}					t_coord;

typedef struct s_engine
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	struct s_coords	*coords;
	struct s_pro_p	*pro_p;
	struct s_lookup	*lookup;
	struct s_trans	*trans;
}					t_engine;

typedef struct s_lexer
{
	int32_t			rot_x;
	int32_t			rot_y;
	int32_t			rot_z;
	int32_t			base_scl;
	int32_t			base_scl_x;
	int32_t			base_scl_y;
	int32_t			base_scl_z;
	int32_t			scl_x;
	int32_t			scl_y;
	int32_t			scl_z;
	int32_t			ofst_x;
	int32_t			ofst_y;
}					t_lexer;

typedef struct s_coords
{
	int32_t			*x;
	int32_t			*y;
	int32_t			*z;
	uint32_t		*color;
	int32_t			width;
	int32_t			height;
	int32_t			size;
}					t_coords;



#endif