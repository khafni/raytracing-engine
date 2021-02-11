/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 09:08:40 by khafni            #+#    #+#             */
/*   Updated: 2021/02/11 15:04:47 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_triangle		triangle(t_tup pa, t_tup pb, t_tup pc, t_tup color)
{
	t_triangle tr;

	tr = malloc(sizeof(struct s_triangle));
	tr->color = color;
	tr->pa = pa;
	tr->pb = pb;
	tr->pc = pc;
	tr->a_to_b_edge = tup_sub(tr->pb, tr->pa);
	tr->b_to_c_edge = tup_sub(tr->pc, tr->pb);
	tr->c_to_a_edge = tup_sub(tr->pa, tr->pc);
	tr->normal = tup_norm(crossproduct(tup_sub(pb, pa), tup_sub(pc, pa)));
	return (tr);
}

int				triangle_intr_check_proj(t_triangle t)
{
	if ((dotproduct(t->a_test_vec, t->normal) > 0) &&
	(dotproduct(t->b_test_vec, t->normal) > 0)
	&& (dotproduct(t->c_test_vec, t->normal) > 0))
		return (1);
	return (0);
}

void			triangle_intersect_helper(t_triangle t)
{
	t->a_test_vec = crossproduct(t->a_to_b_edge, t->a_to_point);
	t->b_test_vec = crossproduct(t->b_to_c_edge, t->b_to_point);
	t->c_test_vec = crossproduct(t->c_to_a_edge, t->c_to_point);
}

t_intersection	triangle_intersect(t_ray r, void *t_)
{
	t_triangle		t;
	t_intersection	intr;
	t_plane			test_plane;

	t = ((t_triangle)t_);
	test_plane = plane(t->pa, t->normal, t->color);
	intr = plane_intersect(r, test_plane);
	if (intr.type == NO_INTERSECTION)
	{
		plane_destroy(test_plane);
		return (intr);
	}
	t->a_to_point = tup_sub(intr.p, t->pa);
	t->b_to_point = tup_sub(intr.p, t->pb);
	t->c_to_point = tup_sub(intr.p, t->pc);
	triangle_intersect_helper(t);
	if (triangle_intr_check_proj(t))
	{
		intr.type = SHAPE_TYPE_TRIANGLE;
		plane_destroy(test_plane);
		return (intr);
	}
	plane_destroy(test_plane);
	intr.type = NO_INTERSECTION;
	return (intr);
}
