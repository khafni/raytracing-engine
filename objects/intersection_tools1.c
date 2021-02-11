/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_tools1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 17:23:01 by khafni            #+#    #+#             */
/*   Updated: 2021/02/11 10:26:50 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_object		object(void *shape, t_shape_type type)
{
	t_object o;

	o = malloc(sizeof(struct s_object));
	o->shape = shape;
	o->type = type;
	return (o);
}

void			object_destroy(void *o_)
{
	t_object o;

	o = (t_object)o_;
	free(o);
}
