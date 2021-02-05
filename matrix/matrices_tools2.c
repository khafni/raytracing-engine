/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices_tools2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 09:57:47 by khafni            #+#    #+#             */
/*   Updated: 2020/12/15 18:24:41 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrices.h"

t_matrice	transpose(t_matrice m)
{
	int			i;
	int			j;
	t_matrice	r;

	r = matrice(m->n_rows, m->n_columns);
	j = 0;
	while (j < m->n_rows)
	{
		i = 0;
		while (i < m->n_columns)
		{
			set_cell(r, j, i, get_cell(m, i, j));
			i++;
		}
		j++;
	}
	return (r);
}

double		matrix_2x2_determinant(t_matrice m)
{
	double r;

	r = get_cell(m, 0, 0) * get_cell(m, 1, 1);
	r -= get_cell(m, 0, 1) * get_cell(m, 1, 0);
	return (r);
}

t_matrice	submatrix(t_matrice m, int row, int column)
{
	t_matrice	sub_m;
	int			i;
	int			j;
	int			k;

	j = 0;
	k = 0;
	sub_m = matrice(m->n_rows - 1, m->n_columns - 1);
	while (j < m->n_rows)
	{
		i = 0;
		while (i < m->n_columns)
		{
			if ((i != column) && (j != row) && (k < (m->n_columns * m->n_rows)))
				*(sub_m->data + (k++)) = get_cell(m, i, j);
			i++;
		}
		j++;
	}
	return (sub_m);
}

double		minor(t_matrice m, int row, int column)
{
	double		n;
	t_matrice	a;

	n = 0;
	if (m->n_columns == 2 && m->n_rows == 2)
		return (0);
	a = submatrix(m, row, column);
	n = determinant(a);
	matrix_destroy(a);
	return (n);
}

double		cofactor(t_matrice m, int row, int column)
{
	int		check_parity;
	double	r;

	check_parity = row + column;
	r = (minor(m, row, column));
	if (check_parity % 2 != 0)
		r *= -1;
	return (r);
}
