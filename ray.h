/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 17:12:02 by khafni            #+#    #+#             */
/*   Updated: 2020/12/17 18:11:22 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "tuples/tuples.h"
# include <stdlib.h>
# include <stdio.h>

/*
** every ray created by the raytracer will have
** a starting point called origin and a vector
** called direciton which says where it points
*/
typedef struct s_ray	t_ray;

struct	s_ray {
	double	t;
	t_tup	direction;
	t_tup	origin;
};
/*
** ray constructor
*/
t_ray	ray(t_tup origin, t_tup direction);

/*
** point at a given distance t along the ray
*/

t_tup	position(t_ray r, double t);
#endif
