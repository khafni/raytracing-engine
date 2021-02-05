/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transformations1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 12:24:33 by khafni            #+#    #+#             */
/*   Updated: 2020/12/17 14:36:34 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrices.h"

t_matrice	translation(double x, double y, double z)
{
	t_matrice m;

	m = identity_matrix(4, 4);
	set_cell(m, 3, 0, x);
	set_cell(m, 3, 1, y);
	set_cell(m, 3, 2, z);
	return (m);
}

t_matrice	scaling(double x, double y, double z)
{
	t_matrice m;

	m = identity_matrix(4, 4);
	set_cell(m, 0, 0, x);
	set_cell(m, 1, 1, y);
	set_cell(m, 2, 2, z);
	return (m);
}

double		radians(double deg)
{
	return ((deg * 180) * M_PI);
}

t_matrice	rotation_x(double degree)
{
	t_matrice m;

	m = identity_matrix(4, 4);
	set_cell(m, 1, 1, cos(degree));
	set_cell(m, 2, 1, -sin(degree));
	set_cell(m, 1, 2, sin(degree));
	set_cell(m, 2, 2, cos(degree));
	return (m);
}

t_matrice	rotation_y(double degree)
{
	t_matrice m;

	m = identity_matrix(4, 4);
	set_cell(m, 0, 0, cos(degree));
	set_cell(m, 2, 0, sin(degree));
	set_cell(m, 0, 2, sin(degree));
	set_cell(m, 2, 2, cos(degree));
	return (m);
}
