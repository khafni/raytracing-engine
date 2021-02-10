/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transformations2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 16:32:02 by khafni            #+#    #+#             */
/*   Updated: 2021/02/10 15:52:47 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrices.h"

t_matrice	rotation_z(double degree)
{
	t_matrice m;

	m = identity_matrix(4, 4);
	set_cell(m, 0, 0, cos(degree));
	set_cell(m, 1, 0, -sin(degree));
	set_cell(m, 0, 1, sin(degree));
	set_cell(m, 1, 1, cos(degree));
	return (m);
}

t_matrice	shearing(t_shear_parms params)
{
	t_matrice m;

	m = identity_matrix(4, 4);
	set_cell(m, 1, 0, params.x_y);
	set_cell(m, 2, 0, params.x_z);
	set_cell(m, 0, 1, params.y_x);
	set_cell(m, 2, 1, params.y_z);
	set_cell(m, 0, 2, params.z_x);
	set_cell(m, 1, 2, params.z_y);
	return (m);
}

t_ray		transform(t_ray r, t_matrice m)
{
	t_ray	rr;

	rr = ray(r.origin, r.direction);
	rr.origin = matrix_4x4_multiply_by_tuple(m, r.origin);
	rr.direction = matrix_4x4_multiply_by_tuple(m, r.direction);
	rr.t = r.t;
	return (rr);
}
