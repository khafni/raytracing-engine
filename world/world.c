/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:41:19 by khafni            #+#    #+#             */
/*   Updated: 2021/01/20 16:53:57 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

t_world		empty_world(void)
{
	t_world w;

	w.objects = empty_garr_64(NULL, sizeof(t_object));
	w.lights = empty_garr_64(NULL, sizeof(t_light));
	w.ambient = am_light(tuple(255, 255, 255), 0);
	return (w);
}

/* t_array		intersect_world(t_world w, t_ray r)
{
	t_array			arr;
	int				i;
	t_intersection	tmp;
	t_object		obj;

	i = 0;
	arr = empty_garr_64(NULL, sizeof(t_intersection));
	while (i < w.objects->len)
	{
		obj = *(t_object*)garr_get(w.objects, i);
		tmp = intersect(obj.shape, obj.type, r);
		if (tmp.type != NO_INTERSECTION)
			garr_add(arr, &tmp);
		i++;
	}
	return (arr);
} */

t_intersection		intersect_world(t_world w, t_ray r)
{	
	int				i;
	t_intersection	tmp;
	double			max;	
	t_object		obj;
	t_intersection	intr;


	i = 0;	
	max = 900000000;
	intr.type = NO_INTERSECTION;
	while (i < w.objects->len)
	{
		obj = *(t_object*)garr_get(w.objects, i);
		tmp = intersect(obj.shape, obj.type, r);
		if (tmp.type != NO_INTERSECTION && tmp.value > 0
		&& tmp.value < max)
		{
			intr = tmp;
			max = tmp.value;
		}
		i++;
	}
	return (intr);	
}

int		is_intersect_world(t_world w, t_ray r)
{	
	int				is_intersect;
	int				i;
	t_intersection	tmp;
	t_object		obj;

	is_intersect = 0;
	i = 0;	
	while (i < w.objects->len)
	{
		obj = *(t_object*)garr_get(w.objects, i);
		tmp = intersect(obj.shape, obj.type, r);
		if (tmp.type != NO_INTERSECTION && tmp.value > 0)
			is_intersect = 1;	
		i++;
	}
	return (is_intersect);
}