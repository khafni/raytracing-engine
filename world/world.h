/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 09:52:52 by khafni            #+#    #+#             */
/*   Updated: 2021/01/20 11:39:34 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H
# include "../objects/objects.h"
# include "../lights/light.h"
# include "../camera/view_transform.h"


typedef struct s_world	*t_world;

struct	s_world
{
	t_arrptr	cameras;
	t_alight	ambient;
	t_arrptr	objects;
	t_arrptr	lights;
};

t_world	empty_world(void);
t_world default_world(void);
void	world_destroy(void *w_);
//t_array intersect_world(t_world w, t_ray r);
t_intersection		intersect_world(t_world w, t_ray r);
int		is_intersect_world(t_world w, t_ray r);
#endif
