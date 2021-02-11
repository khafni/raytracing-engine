/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:41:19 by khafni            #+#    #+#             */
/*   Updated: 2021/02/11 12:33:47 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

t_world				empty_world(void)
{
	t_world w;

	w = malloc(sizeof(struct s_world));
	w->objects = empty_arrptr_create(object_destroy);
	w->lights = empty_arrptr_create(light_destroy);
	w->cameras = empty_arrptr_create(camera_destroy);
	w->ambient = am_light(tuple(255, 255, 255), 0);
	w->mlx_images = empty_arrptr_create(mlx_img_destroy);
	w->camera_index = 0;
	return (w);
}

void				world_destroy(void *w_)
{
	t_world w;
	int		i;

	w = (t_world)w_;
	i = 0;
	arrptr_destroy(w->objects);
	arrptr_destroy(w->lights);
	arrptr_destroy(w->cameras);
	if (w->is_mlx_or_bmp == MLX)
	{
		mlx_destroy_window(w->mlx_ptr, w->mlx_window);
	}
	arrptr_destroy(w->mlx_images);
	free(w);
}

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
	while (i < w->objects->len)
	{
		obj = (t_object)arrptr_get(w->objects, i);
		tmp = intersect(obj->shape, obj->type, r);
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

int					is_intersect_world(t_world w, t_ray r)
{
	int				is_intersect;
	int				i;
	t_intersection	tmp;
	t_object		obj;

	is_intersect = 0;
	i = 0;
	while (i < w->objects->len)
	{
		obj = (t_object)arrptr_get(w->objects, i);
		tmp = intersect(obj->shape, obj->type, r);
		if (tmp.type != NO_INTERSECTION && tmp.value > 0)
			is_intersect = 1;
		i++;
	}
	return (is_intersect);
}
