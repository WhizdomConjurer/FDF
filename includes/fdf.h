/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reriebsc <reriebsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:15:38 by puzzlesanal       #+#    #+#             */
/*   Updated: 2025/11/12 20:27:17 by reriebsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "MLX42/include/MLX42/MLX42.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "libft/libft.h"

# define TILE_SIZE 5
# define SCALE 1000
# define WIDTH 1280
# define HEIGHT 960
# define BACKGROUND 255
# define FOREGROUND 4294967295

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

typedef struct s_transformation
{
	int			rot_x;
	int			rot_y;
	int			rot_z;
	int			base_scl;
	int			base_scl_x;
	int			base_scl_y;
	int			base_scl_z;
	int			scl_x;
	int			scl_y;
	int			scl_z;
	int			ofst_x;
	int			ofst_y;
}					t_transformation;

typedef struct s_lookup
{
	int			sin[360];
	int			cos[360];
}					t_lookup;

typedef struct s_projektion
{
	int32_t			*x;
	int32_t			*y;
	int32_t			*z;
	uint32_t		*color;
	int32_t			idx;
	int32_t			offset_x;
	int32_t			offset_y;
	int32_t			max_prox;
	int32_t			min_prox;
	int32_t			max_proy;
	int32_t			min_proy;
	int32_t			width;
	int32_t			heigth;
}					t_projektion;

typedef struct s_line_calc
{
	struct s_coord	*start;
	struct s_coord	*end;
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
	mlx_t					*mlx;
	mlx_image_t				*img;
	struct s_coords			*coords;
	struct s_projektion		*projektion;
	struct s_lookup			*lookup;
	struct s_transformation	*transformation;
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

//#########Funktions
//##################################################
void				free_token(char **arr);
t_engine			*init_fdf_engine(char *av);
t_coords			*init_coords(int token_count);
void				engine_free(t_engine *engine);
void				init_projection_meta(t_projektion *p, uint32_t w,
						uint32_t h);
uint32_t			*alloc_uint_arr(uint32_t size);
int32_t				*alloc_int_arr(uint32_t size);
t_projektion		*init_projektion(uint32_t w, uint32_t h);
t_transformation	*init_transformation(void);
void				get_offset(t_engine *e);
void				draw(t_engine *e);
void				update_bounds(t_projektion *p, int32_t i);
void				ft_scroll_hook(double xdelta, double ydelta, void *param);
void				ft_resize_hook(int32_t w, int32_t h, void *param);
void				ft_hook(void *param);
void				handle_input(t_engine *e);
uint32_t			*get_color(uint32_t color);
uint32_t			get_rgba(uint32_t r, uint32_t g, uint32_t b, uint32_t a);
int32_t				ft_abs(int32_t num);
void				project(t_engine *e);
void				swap_coords(t_coord **a, t_coord **b);
void				draw_line(t_coord *start, t_coord *end, mlx_image_t *img);
void				fill_img(t_engine *engine, uint32_t color);
void				translate_and_draw(t_engine *e, enum e_rot_dir dir);
void				rotate_and_draw(t_engine *e, enum e_rot_dir axis_dir);
void				scale_and_draw(t_engine *e, enum e_rot_dir axis_dir);
void				reset_and_draw(t_engine *e);
t_coords			*parse_input(char *file_path);
uint32_t			convert_color(char *str);
uint32_t			interpolate_colors(uint32_t c1, uint32_t c2,
						uint32_t max, uint32_t t);


#endif