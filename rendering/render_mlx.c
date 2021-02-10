/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 16:13:33 by khafni            #+#    #+#             */
/*   Updated: 2021/02/10 16:17:06 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

t_image		render_mlx_image(t_camera c, t_world w, void *mlx_ptr)
{
	t_image	im;
	int		i;
	int		j;
	int		i_inc;

	i_inc = 0;
	j = 0;
	im = mlx_create_img(mlx_ptr, w->r_width, w->r_height);
	i = im->height - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < im->width)
		{
			img_set_pixel(im, j, i_inc,
			create_color(color_at(w, ray_for_pixel(c, j, i))));
			j++;
		}
		i_inc++;
		i--;
	}
	return (im);
}

void		render_mlx_generate_imgs(t_world w)
{
	int			i;
	t_camera	c;

	w->mlx_ptr = mlx_init();
	w->mlx_window = mlx_new_window(w->mlx_ptr, w->r_width,
	w->r_height, "window");
	i = 0;
	while (i < w->cameras->len)
	{
		c = arrptr_get(w->cameras, i);
		arrptr_add(w->mlx_images, render_mlx_image(c, w, w->mlx_ptr));
		i++;
	}
}

void		render_mlx(t_world w)
{
	t_image im;

	render_mlx_generate_imgs(w);
	im = arrptr_get(w->mlx_images, w->camera_index);
	mlx_hook(w->mlx_window, 2, 1L << 0, key_pressed, w);
	mlx_hook(w->mlx_window, 17, 1L << 17, red_cross, w);
	mlx_clear_window(w->mlx_ptr, w->mlx_window);
	mlx_put_image_to_window(w->mlx_ptr, w->mlx_window, im->mlx_img, 0, 0);
	mlx_loop(w->mlx_ptr);
}
