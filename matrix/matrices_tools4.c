/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices_tools4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 12:11:16 by khafni            #+#    #+#             */
/*   Updated: 2020/12/15 20:23:49 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrices.h"

BOOL		is_it_invertible(t_matrice m)
{
	if (determinant(m))
		return (TRUE);
	else
		return (FALSE);
}

t_matrice	inverse(t_matrice m)
{
	t_matrice	inversed;
	int			i;
	int			j;
	double		c;
	double		deter;

	deter = determinant(m);
	inversed = matrice(m->n_rows, m->n_columns);
	i = 0;
	while (i < m->n_rows)
	{
		j = 0;
		while (j < m->n_columns)
		{
			c = cofactor(m, i, j);
			set_cell(inversed, i, j, c / deter);
			j++;
		}
		i++;
	}
	return (inversed);
}

t_tup		matrix_4x4_multiply_by_tuple(t_matrice m, t_tup p)
{
	t_tup		r;
	t_matrice	tmp;
	t_matrice	tmp_result;

	r = tuple(0, 0, 0);
	tmp = matrice(4, 1);
	 set_cell(tmp, 0, 0, p.x);
	set_cell(tmp, 0, 1, p.y);
	set_cell(tmp, 0, 2, p.z);
	set_cell(tmp, 0, 3, p.is_point_or_vector);
	
	tmp_result = matrix_multiply(m, tmp);
	
	r.x = get_cell(tmp_result, 0, 0);
	r.y = get_cell(tmp_result, 0, 1);
	r.z = get_cell(tmp_result, 0, 2);
	r.is_point_or_vector = p.is_point_or_vector;
	matrix_destroy(tmp);
	matrix_destroy(tmp_result);
	return (r);
}
t_matrice	matrix_multiply_n_destroy_parms(t_matrice a, t_matrice b)
{
	t_matrice	m;
	int			i;
	int			j;

	j = 0;
	m = matrice(a->n_rows, b->n_columns);
	while (j < a->n_rows)
	{
		i = 0;
		while (i < b->n_columns)
		{
			set_cell(m, i, j, matrix_mutiply_aux(a, b, j, i));
			i++;
		}
		j++;
	}
	matrix_destroy(a);
	matrix_destroy(b);
	return (m);
}