/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 17:28:37 by khafni            #+#    #+#             */
/*   Updated: 2020/12/15 18:22:32 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrices.h"

t_matrice	matrice(int n_lines, int n_colones)
{
	t_matrice m;

	m = malloc(sizeof(struct s_matrice));
	m->n_rows = n_lines;
	m->n_columns = n_colones;
	m->data = malloc(sizeof(double) * m->n_rows * m->n_columns);
	fill_matrice(m, 0);
	return (m);
}

void		matrix_destroy(t_matrice m)
{
	free(m->data);
	free(m);
}

void		set_cell(t_matrice m, int x, int y, double value)
{
	int index;

	index = y * m->n_columns + x;
	m->data[index] = value;
}

double		get_cell(t_matrice m, int x, int y)
{
	int index;

	index = y * m->n_columns + x;
	return (m->data[index]);
}

void		fill_matrice(t_matrice m, double value)
{
	int i;
	int j;

	j = 0;
	while (j < m->n_rows)
	{
		i = 0;
		while (i < m->n_columns)
		{
			set_cell(m, i, j, value);
			i++;
		}
		j++;
	}
}
