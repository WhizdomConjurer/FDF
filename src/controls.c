/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reriebsc <reriebsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:18:18 by reriebsc          #+#    #+#             */
/*   Updated: 2025/11/12 19:18:25 by reriebsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void recompute_scaling(t_transformation *t)
{
    t->scl_x = (t->base_scl_x * t->base_scl) / SCALE;
    t->scl_y = (t->base_scl_y * t->base_scl) / SCALE;
    t->scl_z = (t->base_scl_z * t->base_scl) / SCALE;
    if (t->scl_x < 1) t->scl_x = 1;
    if (t->scl_y < 1) t->scl_y = 1;
    if (t->scl_z < 1) t->scl_z = 1;
}

void translate_and_draw(t_engine *e, enum e_rot_dir dir)
{
    if (dir == X_POS)      e->transformation->ofst_x += TILE_SIZE;
    else if (dir == X_NEG) e->transformation->ofst_x -= TILE_SIZE;
    else if (dir == Y_POS) e->transformation->ofst_y += TILE_SIZE;
    else if (dir == Y_NEG) e->transformation->ofst_y -= TILE_SIZE;
    draw(e);
}

void rotate_and_draw(t_engine *e, enum e_rot_dir axis_dir)
{
    t_transformation *t = e->transformation;
    int step = 5; // Grad-Schritt

    if (axis_dir == X_POS)      t->rot_x = (t->rot_x + step) % 360;
    else if (axis_dir == X_NEG) t->rot_x = (t->rot_x - step + 360) % 360;
    else if (axis_dir == Y_POS) t->rot_y = (t->rot_y + step) % 360;
    else if (axis_dir == Y_NEG) t->rot_y = (t->rot_y - step + 360) % 360;
    else if (axis_dir == Z_POS) t->rot_z = (t->rot_z + step) % 360;
    else if (axis_dir == Z_NEG) t->rot_z = (t->rot_z - step + 360) % 360;

    draw(e);
}

void scale_and_draw(t_engine *e, enum e_rot_dir axis_dir)
{
    t_transformation *t = e->transformation;

    // hier skalieren wir die "Basis"-Skalen der Achsen; danach neu berechnen
    int delta = 1;
    if (axis_dir == Z_POS)      t->base_scl_z += delta;
    else if (axis_dir == Z_NEG && t->base_scl_z > 1) t->base_scl_z -= delta;

    recompute_scaling(t);
    draw(e);
}

void reset_and_draw(t_engine *e)
{
    t_transformation *t = e->transformation;

    t->ofst_x = 0;
    t->ofst_y = 0;

    t->base_scl = SCALE;
    t->base_scl_x = TILE_SIZE;
    t->base_scl_y = TILE_SIZE;
    t->base_scl_z = TILE_SIZE;
    recompute_scaling(t);

    t->rot_x = ((54 % 360) + 360) % 360;
    t->rot_y = ((0  % 360) + 360) % 360;
    t->rot_z = ((35 % 360) + 360) % 360;

    draw(e);
}
