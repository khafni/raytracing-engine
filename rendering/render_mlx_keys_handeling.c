/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mlx_keys_handeling.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 16:17:47 by khafni            #+#    #+#             */
/*   Updated: 2021/02/10 16:27:37 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void		cam_index_incr(t_world w)
{
	if (w->camera_index == (w->cameras->len - 1))
	{
		w->camera_index = 0;
		return ;
	}
	w->camera_index++;
}

void		cam_index_dcrm(t_world w)
{
	if (w->camera_index == 0)
	{
		w->camera_index = w->cameras->len - 1;
		return ;
	}
	w->camera_index--;
}

int			key_pressed(int keycode, t_world w)
{
	t_image im;

	if (keycode == 53)
	{
		world_destroy(w);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == 124)
	{
		cam_index_incr(w);
		mlx_clear_window(w->mlx_ptr, w->mlx_window);
		im = arrptr_get(w->mlx_images, w->camera_index);
		mlx_put_image_to_window(w->mlx_ptr, w->mlx_window, im->mlx_img, 0, 0);
	}
	else if (keycode == 123)
	{
		cam_index_dcrm(w);
		mlx_clear_window(w->mlx_ptr, w->mlx_window);
		im = arrptr_get(w->mlx_images, w->camera_index);
		mlx_put_image_to_window(w->mlx_ptr, w->mlx_window, im->mlx_img, 0, 0);
	}
	return (0);
}

int			red_cross(t_world w)
{
	world_destroy(w);
	exit(EXIT_SUCCESS);
	return (0);
}
