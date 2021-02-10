/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 12:47:19 by khafni            #+#    #+#             */
/*   Updated: 2021/02/10 15:53:50 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

double	degree_to_radians(double degree)
{
	double r;

	r = (degree * M_PI / 180.0);
	return (r);
}

void	add_camera(char *line, t_world w)
{
	char		**cmps;
	t_camera	c;

	cmps = ft_split(line, ' ');
	c = camera(w->r_height, w->r_width, degree_to_radians(ft_atof(cmps[3])),
	view_transform(get_tuple(cmps[1]), tup_norm(get_tuple(cmps[2])),
	tuple(-1, 0, 0)));
	c->from = get_tuple(cmps[1]);
	arrptr_add(w->cameras, c);
	free_split(cmps);
}
