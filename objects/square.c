/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:15:30 by khafni            #+#    #+#             */
/*   Updated: 2021/02/07 17:58:57 by khafni           ###   ########.fr       */
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

t_intersection		square_intersect(t_ray r, void *sq_)
{
	t_intersection	intr;
	t_plane			p;
	t_square		sq;
	
	sq = ((t_square)sq_);
	p = plane(sq->center, sq->normal, sq->color);
	intr = plane_intersect(r, p);
	if (intr.type == NO_INTERSECTION)
	{
		plane_destroy(p);
		return (intr);
	}
	t_tup width = crossproduct(sq->normal, tuple(0, 1, 0));
	if (tup_eq(width, tuple(0, 0, 0)))
		width = crossproduct(sq->normal, tuple(0, 0, 1));
	width = tup_norm(width);
	t_tup height = tup_norm(crossproduct(sq->normal, width));
	t_tup v = tup_sub(intr.p, sq->center);
	float proj1 = dotproduct(v, width);
	float proj2 = dotproduct(v, height);
	if ((proj1 - (sq->side_size / 2) < 0 && proj1 - (- sq->side_size / 2) > 0)
	&& (proj2 - (sq->side_size / 2) < 0 && proj2 - (-sq->side_size / 2)) > 0)
/* 	if ((proj1 < (sq->side_size / 2) && proj1 > (- sq->side_size / 2)) && (proj2 < (sq->side_size / 2) && proj2 > (-sq->side_size / 2)))
 */
if (((proj1 - (sq->side_size / 2.0)) < 0.0001 && (proj1 - (- sq->side_size / 2.0)) > 0.0001) && ((proj2 - (sq->side_size / 2.0)) < 0.001) && ((proj2 - (-sq->side_size / 2.0)) > 0.0001))
{
		intr.shape = sq_;
		intr.type = SHAPE_TYPE_SQUARE;
		//intr = intersection(&sq, intr.value, SHAPE_TYPE_SQUARE);
		intr.color = sq->color;
		plane_destroy(p);
		return (intr);
	}	
	intr.type = NO_INTERSECTION;
	plane_destroy(p);
	return (intr);
}