/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 16:53:02 by khafni            #+#    #+#             */
/*   Updated: 2021/01/20 15:18:15 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_sphere			sphere(t_tup center, int radius, t_tup color)
{
	t_sphere s;

	s = malloc(sizeof(struct s_sphere));
	s->center = center; 
	s->radius = radius;
	s->color = color;
	return (s);
}


void				sphere_destroy(void *s_)
{
	t_sphere s;

	s = (t_sphere)s_;
	free(s_);
}
t_sphere_equat_sol	sphere_eqt_solver(t_ray r, t_sphere s)
{
	t_sphere_equat_sol	sol;
	t_tup				sphere_to_ray;

	sphere_to_ray = tup_sub(r.origin, s->center);
	sol.a = dotproduct(r.direction, r.direction);
	sol.b = 2 * dotproduct(r.direction, sphere_to_ray);
	sol.c = dotproduct(sphere_to_ray, sphere_to_ray) - s->radius * s->radius;
	sol.discriminant = sol.b * sol.b - 4 * sol.a * sol.c;
	return (sol);
}

t_intersection		sphere_intersect(t_ray r, void *s_)
{
	t_sphere_equat_sol	sol;
	t_sphere			s;
	t_intersection		inters;

	s = ((t_sphere)s_);
	sol = sphere_eqt_solver(r, s);
	if (sol.discriminant < 0)
	{
		inters = intersection(s_, 0, NO_INTERSECTION);
		return (inters);
	}
	sol.root1 = (-sol.b - sqrt(sol.discriminant)) / (2 * sol.a);
	sol.root2 = (-sol.b + sqrt(sol.discriminant)) / (2 * sol.a);
	inters = intersection(s_, sol.root1, SHAPE_TYPE_SPHERE);
	inters.p = position(r, inters.value);
	inters.normal = sh_normal_at(s, inters.p);
	inters.color = s->color;
	return (inters);
}

t_tup				sh_normal_at(t_sphere sh, t_tup p)
{
	return (tup_norm(tup_sub(p, sh->center)));
}