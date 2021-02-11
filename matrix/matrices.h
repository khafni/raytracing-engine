/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 16:29:02 by khafni            #+#    #+#             */
/*   Updated: 2021/02/11 10:31:53 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRICES_H
# define MATRICES_H

# include "stdio.h"
# include "stdlib.h"
# include "../tuples/tuples.h"
# include "../ray.h"
# define BOOL char
# define TRUE 1
# define FALSE 0

/*
** LINEAR ALGEBRA 101 no libraries needed
** 100% CPU BASED :(
*/

/*
** a matrix is just a 2D array of n_rows lines
** and n_columns columns and i use here the 1D
** array implementation of 2D arrays for efficiency reasons
*/
typedef struct s_matrice	*t_matrice;

struct		s_matrice
{
	int		n_rows;
	int		n_columns;
	double	*data;
};

/*
**	constructor, distructor and matrices handeling methods
*/
t_matrice	matrice(int n_lines, int n_colones);
void		matrix_destroy(t_matrice m);
void		set_cell(t_matrice m, int x, int y, double value);
double		get_cell(t_matrice m, int x, int y);
t_matrice	identity_matrix(int n_lines, int n_colones);
t_matrice	matrix_clone(t_matrice m);
void		fill_matrice(t_matrice m, double value);
void		fill_matrice_with_increament(t_matrice m, double value);
BOOL		matrices_equal(t_matrice m1, t_matrice m2);
double		minor(t_matrice m, int row, int column);
double		cofactor(t_matrice m, int row, int column);
double		matrix_mutiply_aux(t_matrice m1, t_matrice m2, int line,
int column);
t_matrice	matrix_multiply(t_matrice m1, t_matrice m2);
t_matrice	matrix_multiply_n_destroy_parms(t_matrice m1, t_matrice m2);
t_matrice	matrix_multiply_by_scalar(t_matrice a, double s);
t_matrice	transpose(t_matrice m);
void		matrix_4x4_debug(t_matrice m);
void		matrix_debug(t_matrice m);
double		matrix_2x2_determinant(t_matrice m);
t_matrice	submatrix(t_matrice m, int row, int column);
double		matrix_3x3_determinant(t_matrice m);
double		m_4x4_cofactor(t_matrice m, int row, int column);
double		matrix_4x4_determinant(t_matrice m);
double		determinant(t_matrice m);
t_matrice	adjoint(t_matrice m);
BOOL		is_it_invertible(t_matrice m);
t_matrice	inverse(t_matrice m);
t_matrice	tup_to_matrix(t_tup t);
t_tup		matrix_to_tup(t_matrice m);
t_tup		matrix_4x4_multiply_by_tuple(t_matrice m, t_tup p);

/*
**	|||||||||||||||||||||||||||||||||||||
**	||								   ||
**	|| LINEAR TRANSFORMATIONS MATRICES ||
**	||								   ||
**	|||||||||||||||||||||||||||||||||||||
*/

/*
** here i implement few matrices that enables many
** transformations of a whole vector space thus
** i can do something like a retation of a point in space
** via just multiplying a retation matrice by that point
*/

/*
**	function that returns a translation matrix
**	x, y, z : how much/in which direction, we want
**  to translate a point
*/
t_matrice	translation (double x, double y, double z);

/*
** function that returns a scaling matrix
** (you can make your vectors coordonates (v.x, v.y, v.z)
** bigger or smaller)
*/
t_matrice	scaling(double x, double y, double z);

/*
** transform degree to radians
*/

double		radians(double deg);

/*
** function that returns a rotation by the x axis
** transformation matrix (takes a point p[x, y, z]
** and rotates it on the OX axis when you multiply it
** by the point)
*/

t_matrice	rotation_x(double degree);

/*
** function that returns a rotation by the y axis
** transformation matrix (takes a point p[x, y, z]
** and rotates it on the OX axis when you multiply it
** by the point)
*/

t_matrice	rotation_y(double degree);

/*
** function that returns a rotation by the z axis
** transformation matrix (takes a point p[x, y, z]
** and rotates it on the OX axis when you multiply it
** by the point)
*/

t_matrice	rotation_z(double degree);

/*
**	a transformation matrix that changes every
** component in propotion of the other two
** components. so the x component changes in
** proportion to y and z
*/
typedef struct s_shear_parms	t_shear_parms;

struct		s_shear_parms
{
	double	x_y;
	double	x_z;
	double	y_x;
	double	y_z;
	double	z_x;
	double	z_y;
};

t_matrice	shearing(t_shear_parms params);
/*
** apply a linear transformation/s on a ray
*/
t_ray		transform(t_ray r, t_matrice m);

#endif
