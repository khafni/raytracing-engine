/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 14:28:26 by khafni            #+#    #+#             */
/*   Updated: 2021/02/08 18:45:36 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "view_transform.h"

/* t_matrice	view_transform(t_tup from, t_tup to, t_tup up)
{
	t_matrice	orient;
	t_tup		forward;
	t_tup		left;
	t_tup		true_up;
	t_matrice	tmp;

	orient = identity_matrix(4, 4);
	//forward = tup_norm(tup_sub(to, from));	
	forward = tup_norm(to);
	left = crossproduct(forward, tup_norm(up));
	if (tup_eq(left, tuple(0, 0, 0)))
		left = crossproduct(forward, tuple(0, 0, 1));
	left = tup_norm(left);
	true_up = tup_norm(crossproduct(left, forward));
	set_cell(orient, 0, 0, left.x);
	set_cell(orient, 1, 0, left.y);
	set_cell(orient, 2, 0, left.z);
	set_cell(orient, 0, 1, true_up.x);
	set_cell(orient, 1, 1, true_up.y);
	set_cell(orient, 2, 1, true_up.z);
	set_cell(orient, 0, 2, -forward.x);
	set_cell(orient, 1, 2, -forward.y);
	set_cell(orient, 2, 2, -forward.z);
	
	return (matrix_multiply_n_destroy_parms(orient, translation(-from.x, -from.y, -from.z)));
	//return (matrix_multiply_n_destroy_parms(orient, identity_matrix(4, 4)));	
} */

t_tup		check_cross(t_tup right, t_tup cam_vector)
{
	t_tup	forward;

	forward = tuple(0, 1, 0);
	right = crossproduct(forward, cam_vector);
	if (right.x == 0 && right.y == 0 && right.z == 0)
	{
		forward = tup_norm(tuple(1, 1, 1));
		right = tup_norm(crossproduct(forward, cam_vector));
		right = tup_norm(right);
		return (right);
	}
	right = tup_norm(right);
	return (right);
}


t_matrice	view_transform(t_tup from, t_tup to, t_tup tmp)
{
	t_matrice	orient;
	t_tup		right;
	t_tup		up;
	
	orient = identity_matrix(4, 4);
	//forward = tup_norm(tup_sub(to, from));	
	to = tup_norm(to);
	right = check_cross(tuple(0, 0, 0), to);
	right = tup_norm(right);
	up = crossproduct(to, right);
	set_cell(orient, 0, 0, right.x);
	set_cell(orient, 1, 0, right.y);
	set_cell(orient, 2, 0, right.z);
	set_cell(orient, 0, 1, up.x);
	set_cell(orient, 1, 1, up.y);
	set_cell(orient, 2, 1, up.z);
	set_cell(orient, 0, 2, to.x);
	set_cell(orient, 1, 2, to.y);
	set_cell(orient, 2, 2, to.z);
	set_cell(orient, 0, 3, from.x);
	set_cell(orient, 1, 3, from.y);
	set_cell(orient, 2, 3, from.z);
	//return (matrix_multiply_n_destroy_parms(orient, translation(-from.x, -from.y, -from.z)));
	return (orient);	
}

void		calc_pixel_size(t_camera c)
{
	float aspect;
	float half_view;

	half_view = tan(c->fov / 2);
	aspect = (float)c->hsize / (float)c->vsize;
	//aspect = 16.0 / 9.0;

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
	
	c->pixel_size = (c->half_width * 2) / (float)c->hsize;
}

t_w_crds	calc_w_crds(t_camera c, int px, int py)
{
	float		xoffset;
	float		yoffset;
	t_w_crds	world_coordinates;
	float		aspect;

	aspect = (float)c->hsize / (float)c->vsize;
	xoffset = ((float)px + .5f) * c->pixel_size;
	yoffset = ((float)py + .5f) * c->pixel_size;
	world_coordinates.world_x = c->half_width - xoffset;
	world_coordinates.world_y = c->half_height - yoffset;
	
	world_coordinates.world_x = (2 * ((px + 0.5) / c->hsize) - 1) * tan(c->fov / 2) * aspect;
	world_coordinates.world_y = (1 - 2 * ((py + 0.5) / c->vsize) * tan(c->fov / 2));
	return (world_coordinates);
}

/* t_ray		ray_for_pixel(t_camera c, int px, int py)
{
	t_w_crds	w_crds;
	t_tup		pixel;	
	t_tup		direction;

	w_crds = calc_w_crds(c, px, py);
	pixel = matrix_4x4_multiply_by_tuple(c->tran_inv,
	point(w_crds.world_x, w_crds.world_y, -1));
	direction = tup_norm(tup_sub(pixel, c->origin));
	return (ray(c->origin, direction));
} */

t_tup		get_direction(int x, int y, t_camera camera)
{
	double fov_coeff;
	double aspect_ratio;
	double p_x;
	double p_y;

	fov_coeff = tan((double)camera->fov / 2 * M_PI / 180);
	aspect_ratio = (double)camera->hsize / (double)camera->vsize;
	p_x = (2 * (x + 0.5) / (double)camera->hsize - 1) *
		aspect_ratio * fov_coeff;
	p_y = (1 - 2 * (y + 0.5) / (double)camera->vsize) * fov_coeff;
	return (tuple(p_x, p_y, 1));
}

t_ray		ray_for_pixel(t_camera c, int px, int py)
{
	t_tup		pixel;	
	t_tup		direction;
	

	pixel = matrix_4x4_multiply_by_tuple(c->transform,
	get_direction(px, py, c));
	direction = tup_norm(tup_sub(pixel, c->origin));
	return (ray(c->origin, direction));
}