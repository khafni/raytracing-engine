/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_objects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 16:12:46 by khafni            #+#    #+#             */
/*   Updated: 2021/02/07 16:27:26 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"



void	get_sphere(char *line, t_world w)
{
	char		**cmps;
	t_sphere	s;
	t_object	o;

	cmps = ft_split(line, ' ');
	s = sphere(get_tuple(cmps[1]), ft_atof(cmps[2]) / 2.0, get_tuple(cmps[3]));
	o = object(s, SHAPE_TYPE_SPHERE);
	arrptr_add(w->objects, o);
	free_split(cmps);
}

void	get_plane(char *line, t_world w)
{
	char		**cmps;
	t_object	o;
	t_plane		pl;

	cmps = ft_split(line, ' ');
	pl = plane(get_tuple(cmps[1]), get_tuple(cmps[2]), get_tuple(cmps[3]));
	o = object(pl, SHAPE_TYPE_PLANE);
	arrptr_add(w->objects, o);
	free_split(cmps);
}

void	get_square(char *line, t_world w)
{
	char		**cmps;
	t_object	o;
	t_square	sq;

	cmps = ft_split(line, ' ');
	sq = square(get_tuple(cmps[1]), get_tuple(cmps[2]),
	ft_atof(cmps[3]), get_tuple(cmps[4]));
	o = object(sq, SHAPE_TYPE_SQUARE);
	arrptr_add(w->objects, o);
	free_split(cmps);
}

void	get_cylinder(char *line, t_world w)
{
	char		**cmps;
	t_object	o;
	t_cylinder	cy;

	cmps = ft_split(line, ' ');
	cy = cylinder(get_tuple(cmps[1]), get_tuple(cmps[2]), ft_atof(cmps[3]),
	ft_atof(cmps[4]), get_tuple(cmps[5]));
	o = object(cy, SHAPE_TYPE_CYLINDER);
	arrptr_add(w->objects, o);
	free_split(cmps);
}

void	get_triangle(char *line, t_world w)
{
	char		**cmps;
	t_object	o;
	t_triangle	tr;

	cmps = ft_split(line, ' ');
	tr = triangle(get_tuple(cmps[1]), get_tuple(cmps[2]),
	get_tuple(cmps[3]), get_tuple(cmps[4]));
	o = object(tr, SHAPE_TYPE_TRIANGLE);
	arrptr_add(w->objects, o);
	free_split(cmps);
}
