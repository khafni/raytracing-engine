/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 15:58:54 by khafni            #+#    #+#             */
/*   Updated: 2021/02/12 08:47:05 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

t_tup		color_at(t_world w, t_ray r)
{
	t_tup			c;
	t_intersection	xs;

	xs = intersect_world(w, r);
	if (xs.type == NO_INTERSECTION)
		return (tuple(0, 0, 0));
	c = lighting(xs, w);
	return (c);
}

void		render_bmp(t_world w)
{
	t_bmp		canvas;
	int			i;
	int			j;
	t_camera	c;

	c = arrptr_get(w->cameras, 0);
	i = 0;
	j = 0;
	canvas = create_pixels_array(c->vsize, c->hsize);
	while (i < canvas.height)
	{
		j = 0;
		while (j < canvas.width)
		{
			set_bmp_pixel(&canvas, j, i,
			create_color(color_at(w, ray_for_pixel(c, j, i))));
			j++;
		}
		i++;
	}
	write_bmp("screenshot.bmp", &canvas);
}

void		render(int argc, t_world w)
{
	if (argc == 3)
	{
		w->is_mlx_or_bmp = BMP;
		render_bmp(w);
		world_destroy(w);
	}
	else
		render_mlx(w);
}
