/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices_tools3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 14:36:11 by khafni            #+#    #+#             */
/*   Updated: 2020/12/15 18:25:20 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrices.h"

double		matrix_3x3_determinant(t_matrice m)
{
	double n;

	n = get_cell(m, 0, 0) * cofactor(m, 0, 0);
	n += get_cell(m, 0, 1) * cofactor(m, 1, 0);
	n += get_cell(m, 0, 2) * cofactor(m, 2, 0);
	return (n);
}

/*
** private function
*/

double		matrix_3x3_determinant_and_destroym(t_matrice m)
{
	double n;

	n = matrix_3x3_determinant(m);
	matrix_destroy(m);
	return (n);
}

double		m_4x4_cofactor(t_matrice m, int row, int column)
{
	int		check_parity;
	double	r;

	check_parity = row + column;
	r = matrix_3x3_determinant_and_destroym(submatrix(m, row, column));
	if (check_parity % 2 != 0)
		r *= -1;
	return (r);
}

double		matrix_4x4_determinant(t_matrice m)
{
	double n;

	n = get_cell(m, 0, 0) * m_4x4_cofactor(m, 0, 0);
	n += get_cell(m, 0, 1) * m_4x4_cofactor(m, 1, 0);
	n += get_cell(m, 0, 2) * m_4x4_cofactor(m, 2, 0);
	n += get_cell(m, 0, 3) * m_4x4_cofactor(m, 3, 0);
	return (n);
}

double		determinant(t_matrice m)
{
	if (m->n_columns == 2 && m->n_rows == 2)
		return (matrix_2x2_determinant(m));
	else if (m->n_columns == 3 && m->n_rows == 3)
		return (matrix_3x3_determinant(m));
	else if (m->n_columns == 4 && m->n_rows == 4)
		return (matrix_4x4_determinant(m));
	else
		return (0);
}
