/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 09:52:52 by khafni            #+#    #+#             */
/*   Updated: 2021/02/09 17:58:29 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H
# include "../objects/objects.h"
# include "../lights/light.h"
# include "../camera/view_transform.h"
# include "../mlx_image.h"
# define MLX	0
# define BMP 1


typedef struct s_world	*t_world;

struct	s_world
{
	t_arrptr	cameras;
	t_alight	ambient;
	t_arrptr	objects;
	t_arrptr	lights;
	int			r_width;
	int			r_height;
	t_arrptr	mlx_images;
	int			is_mlx_or_bmp;
	void		*mlx_ptr;
	void		*mlx_window;
};

t_world	empty_world(void);
t_world default_world(void);
void	world_destroy(void *w_);
//t_array intersect_world(t_world w, t_ray r);
t_intersection		intersect_world(t_world w, t_ray r);
int		is_intersect_world(t_world w, t_ray r);
#endif
