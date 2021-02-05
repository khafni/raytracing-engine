/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 17:10:27 by khafni            #+#    #+#             */
/*   Updated: 2021/01/20 16:52:55 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shading.h"



t_tup		diffuse_lighting(t_light l, t_world *w, t_intersection *i)
{
	t_tup lightv;
	t_tup diffuse;
	float light_dot_normal;

	lightv = tup_norm(tup_sub(l.position, i->p));
	light_dot_normal = dotproduct(lightv, i->normal);
	//printf("%f\n", i->normal.y);
	if (light_dot_normal < 0)
		diffuse = tuple(0, 0, 0);
	else
	{
		diffuse.x = minnum(((i->color.x + l.color.x) / 2) * l.intensity, 255);
		diffuse.y = minnum(((i->color.y + l.color.y) / 2) * l.intensity, 255);
		diffuse.z = minnum(((i->color.z + l.color.z) / 2) * l.intensity, 255);
		diffuse = tup_multi(diffuse, maxnum(light_dot_normal, 0));
	}
	return (diffuse);
}

t_tup		lighting(t_intersection i, t_world w)
{
    int		index;
	t_light l;
	t_tup	f_col;
	int		is_sh;
    t_array tarr;

	is_sh = 0;
	f_col = tuple(0, 0, 0);
	index = 0;
	f_col.x = minnum(i.color.x * w.ambient.color.x, 255);
	f_col.y = minnum(i.color.y * w.ambient.color.y, 255);
	f_col.z = minnum(i.color.z * w.ambient.color.z, 255);
	f_col = tup_multi(f_col, w.ambient.ratio);
	while (index < w.lights->len)
	{
		l = *(t_light*)garr_get(w.lights, index);
       	if (!is_intersect_world(w, ray(i.p, tup_norm(tup_sub(l.position, i.p)))))
			f_col = tup_add(f_col, diffuse_lighting(l, &w, &i));
		index++;
	}	
	f_col.x = minnum(f_col.x, 255);
	f_col.y = minnum(f_col.y, 255);
	f_col.z = minnum(f_col.z, 255);
	return (f_col);
}