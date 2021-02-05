/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 14:28:26 by khafni            #+#    #+#             */
/*   Updated: 2021/01/21 17:25:08 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "view_transform.h"

t_matrice	view_transform(t_tup from, t_tup to, t_tup up)
{
	t_matrice	orient;
	t_tup		forward;
	t_tup		left;
	t_tup		true_up;

	orient = identity_matrix(4, 4);
	//forward = tup_norm(tup_sub(to, from));	
	forward = tup_norm(to);
	left = crossproduct(forward, tup_norm(up));
	if (tup_eq(left, tuple(0, 0, 0)))
		left = crossproduct(forward, tuple(0, 0, 1));
	true_up = crossproduct(left, forward);
	set_cell(orient, 0, 0, left.x);
	set_cell(orient, 1, 0, left.y);
	set_cell(orient, 2, 0, left.z);
	set_cell(orient, 0, 1, true_up.x);
	set_cell(orient, 1, 1, true_up.y);
	set_cell(orient, 2, 1, true_up.z);
	set_cell(orient, 0, 2, -forward.x);
	set_cell(orient, 1, 2, -forward.y);
	set_cell(orient, 2, 2, -forward.z);
	return (matrix_multiply(orient, translation(-from.x, -from.y, -from.z)));
}

void		calc_pixel_size(t_camera *c)
{
	float aspect;
	float half_view;

	half_view = tan(c->fov / 2);
	aspect = (float)c->hsize / (float)c->vsize;
	if (aspect >= 1)
	{
		c->half_width = half_view;
		c->half_height = half_view / aspect;
	}
	else
	{
		c->half_width = half_view * aspect;
		c->half_height = half_view;
	}
	c->pixel_size = (c->half_width * 2) / c->hsize;
}

t_camera	camera(int hsize, int vsize, float fov, t_matrice tr)
{
	t_camera c;

	c.hsize = hsize;
	c.vsize = vsize;
	c.fov = fov;
	c.transform = tr;
	c.tran_inv = inverse(c.transform);
	c.origin = matrix_4x4_multiply_by_tuple(c.tran_inv,
	point(0, 0, 0));
	calc_pixel_size(&c);
	return (c);
}

t_w_crds	calc_w_crds(t_camera c, int px, int py)
{
	float		xoffset;
	float		yoffset;
	t_w_crds	world_coordinates;

	xoffset = ((float)px + .5f) * c.pixel_size;
	yoffset = ((float)py + .5f) * c.pixel_size;
	world_coordinates.world_x = c.half_width - xoffset;
	world_coordinates.world_y = c.half_height - yoffset;
	return (world_coordinates);
}

t_ray		ray_for_pixel(t_camera c, int px, int py)
{
	t_w_crds	w_crds;
	t_tup		pixel;	
	t_tup		direction;

	w_crds = calc_w_crds(c, px, py);
	pixel = matrix_4x4_multiply_by_tuple(c.tran_inv,
	point(w_crds.world_x, w_crds.world_y, -1));
	direction = tup_norm(tup_sub(pixel, c.origin));
	return (ray(c.origin, direction));
}
