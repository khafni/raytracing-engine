/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples_tools_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 10:33:26 by khafni            #+#    #+#             */
/*   Updated: 2020/12/08 10:35:25 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

float	tup_mag(t_tup vec)
{
	double m;

	m = 0;
	m = sqrt(pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2));
	return (m);
}

t_tup	tup_norm(t_tup vec)
{
	t_tup	norm;
	double	mag;

	norm = tuple(0, 0, 0);
	mag = tup_mag(vec);
	norm.x = vec.x / mag;
	norm.y = vec.y / mag;
	norm.z = vec.z / mag;
	return (norm);
}

float	dotproduct(t_tup v1, t_tup v2)
{
	return ((v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z));
}

t_tup	crossproduct(t_tup v1, t_tup v2)
{
	t_tup cpv;

	cpv = tuple(0, 0, 0);
	cpv.x = (v1.y * v2.z) - (v1.z * v2.y);
	cpv.y = (v1.z * v2.x) - (v1.x * v2.z);
	cpv.z = (v1.x * v2.y) - (v1.y * v2.x);
	return (cpv);
}

void	tup_copy(t_tup *src, t_tup *dst)
{
	dst->x = src->x;
	dst->y = src->y;
	dst->z = src->z;
}
