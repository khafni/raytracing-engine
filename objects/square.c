/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:15:30 by khafni            #+#    #+#             */
/*   Updated: 2021/02/11 18:53:06 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_square			square(t_tup center, t_tup n, double s_size, t_tup col)
{
	t_square sq;

	sq = malloc(sizeof(struct s_square));
	sq->center = center;
	sq->normal = n;
	sq->side_size = s_size;
	sq->color = col;
	return (sq);
}

t_square_base		square_base_get(t_square sq, t_intersection intr)
{
	t_square_base b;

	b.width = crossproduct(sq->normal, tuple(0, 1, 0));
	if (tup_eq(b.width, tuple(0, 0, 0)))
		b.width = crossproduct(sq->normal, tuple(0, 0, 1));
	b.width = tup_norm(b.width);
	b.height = tup_norm(crossproduct(sq->normal, b.width));
	b.v = tup_sub(intr.p, sq->center);
	b.proj1 = dotproduct(b.v, b.width);
	b.proj2 = dotproduct(b.v, b.height);
	return (b);
}

int					check_projection(t_square_base sb, t_square sq)
{
	if (((sb.proj1 - (sq->side_size / 2.0)) < 0.0001
	&& (sb.proj1 - (-sq->side_size / 2.0)) > 0.0001)
	&& ((sb.proj2 - (sq->side_size / 2.0)) < 0.001)
	&& ((sb.proj2 - (-sq->side_size / 2.0)) > 0.0001))
		return (1);
	return (0);
}

t_intersection		square_intersect(t_ray r, void *sq_)
{
	t_intersection	intr;
	t_plane			p;
	t_square		sq;
	t_square_base	sb;

	sq = ((t_square)sq_);
	p = plane(sq->center, sq->normal, sq->color);
	intr = plane_intersect(r, p);
	if (intr.type == NO_INTERSECTION)
	{
		plane_destroy(p);
		return (intr);
	}
	sb = square_base_get(sq, intr);
	if (check_projection(sb, sq))
	{
		intr.shape = sq_;
		intr.type = SHAPE_TYPE_SQUARE;
		plane_destroy(p);
		return (intr);
	}
	intr.type = NO_INTERSECTION;
	plane_destroy(p);
	return (intr);
}
