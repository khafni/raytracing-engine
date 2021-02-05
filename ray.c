/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 17:30:29 by khafni            #+#    #+#             */
/*   Updated: 2020/12/17 17:36:31 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_ray	ray(t_tup origin, t_tup direction)
{
	t_ray r;

	r.origin = origin;
	r.direction = direction;
	return (r);
}

t_tup	position(t_ray r, double t)
{
	t_tup result;

	result = tup_add(r.origin, tup_multi(r.direction, t));
	return (result);
}
