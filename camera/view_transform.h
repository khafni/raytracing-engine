/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_transform.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 14:27:29 by khafni            #+#    #+#             */
/*   Updated: 2021/01/21 17:24:45 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEW_TRANSFORM_H
# define VIEW_TRANSFORM_H
# include "../matrix/matrices.h"


t_matrice	view_transform(t_tup from, t_tup to, t_tup up);

typedef struct s_camera	t_camera;

struct		s_camera
{
	int			hsize;
	int			vsize;
	float		fov;
	float		pixel_size;
	float		half_width;
	float		half_height;
	t_matrice	transform;
	t_matrice	tran_inv;
	t_tup		origin;
	t_tup		to;
};

t_camera	camera(int hsize, int vsize, float fov, t_matrice tr);

typedef struct
{
	float	world_x;
	float	world_y;
}			t_w_crds;

t_ray		ray_for_pixel(t_camera c, int px, int py);

#endif
