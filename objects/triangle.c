/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student->42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 18:15:02 by khafni            #+#    #+#             */
/*   Updated: 2021/01/21 16:27:02 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_triangle triangle(t_tup pa, t_tup pb, t_tup pc, t_tup color)
{
	t_triangle tr;

	tr = malloc(sizeof(struct s_triangle));
	tr->color = color;
	tr->pa = pa;
	tr->pb = pb;
	tr->pc = pc;
	tr->normal = tup_norm(crossproduct(tup_sub(pb, pa), tup_sub(pc, pa)));
	return (tr);
}

t_intersection triangle_intersect(t_ray r, void *t_)
{
	t_triangle t;
	t_intersection intr;

	t = ((t_triangle )t_);
	t_plane test_plane = plane(t->pa, t->normal, t->color);
	intr = plane_intersect(r, test_plane);
	if (intr.type == NO_INTERSECTION)
		return (intr);
		
	t_tup a_to_b_edge = tup_sub(t->pb, t->pa);
	t_tup b_to_c_edge = tup_sub(t->pc, t->pb);
	t_tup c_to_a_edge = tup_sub(t->pa, t->pc);

	t_tup a_to_point = tup_sub(intr.p, t->pa);
	t_tup b_to_point = tup_sub(intr.p, t->pb);
	t_tup c_to_point = tup_sub(intr.p, t->pc);

	t_tup a_test_vec = crossproduct(a_to_b_edge, a_to_point);
	t_tup b_test_vec = crossproduct(b_to_c_edge, b_to_point);
	t_tup c_test_vec = crossproduct(c_to_a_edge, c_to_point);
	if ((dotproduct(a_test_vec, t->normal) > 0) && (dotproduct(b_test_vec, t->normal) > 0) && (dotproduct(c_test_vec, t->normal) > 0))
	{
		intr.type = SHAPE_TYPE_TRIANGLE;
		return (intr);
	}
	intr.type = NO_INTERSECTION;
	return (intr);
}