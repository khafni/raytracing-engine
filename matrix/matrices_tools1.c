/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices_tools1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 17:54:36 by khafni            #+#    #+#             */
/*   Updated: 2020/12/15 20:16:10 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrices.h"

BOOL		matrices_equal(t_matrice m1, t_matrice m2)
{
	int i;
	int j;

	if ((m1->n_columns != m2->n_columns) || (m1->n_rows != m2->n_rows))
		return (FALSE);
	j = 0;
	while (j < m1->n_rows)
	{
		i = 0;
		while (i < m1->n_columns)
		{
			if (get_cell(m1, j, i) != get_cell(m2, j, i))
				return (FALSE);
			i++;
		}
		j++;
	}
	return (TRUE);
}

double		matrix_mutiply_aux(t_matrice m1, t_matrice m2, int line, int column)
{
	double	s;
	int		k;

	k = 0;
	s = 0;
	while (k < m1->n_columns)
	{
		s += get_cell(m1, k, line) * get_cell(m2, column, k);
		k++;
	}
	return (s);
}

t_matrice	matrix_multiply(t_matrice a, t_matrice b)
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
	return (m);
}

t_matrice	identity_matrix(int n_lines, int n_colones)
{
	t_matrice	m;
	int			i;

	m = matrice(n_lines, n_colones);
	i = 0;
	while (i < m->n_columns)
	{
		set_cell(m, i, i, 1);
		i++;
	}
	return (m);
}

t_matrice	matrix_clone(t_matrice m)
{
	t_matrice	c;
	int			k;

	k = 0;
	c = matrice(m->n_rows, m->n_columns);
	while (k < (m->n_columns * m->n_rows))
	{
		*(c->data + (k)) = *(m->data + (k));
		k++;
	}
	return (c);
}
