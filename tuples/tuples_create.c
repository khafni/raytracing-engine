/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 10:29:16 by khafni            #+#    #+#             */
/*   Updated: 2021/02/10 16:29:52 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

t_tup	tuple(float x, float y, float z)
{
	t_tup	t;

	t.x = x;
	t.y = y;
	t.z = z;
	return (t);
}

t_tup	point(float x, float y, float z)
{
	t_tup t;

	t.x = x;
	t.y = y;
	t.z = z;
	t.is_point_or_vector = POINT;
	return (t);
}

t_tup	vector(float x, float y, float z)
{
	t_tup t;

	t.x = x;
	t.y = y;
	t.z = z;
	t.is_point_or_vector = VECTOR;
	return (t);
}

int		tup_eq(t_tup t1, t_tup t2)
{
	if ((t1.x == t2.x) && (t1.y == t2.y) && (t1.z == t2.z))
		return (1);
	else
		return (0);
}
