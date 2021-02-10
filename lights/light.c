/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 17:07:15 by khafni            #+#    #+#             */
/*   Updated: 2021/02/10 15:51:12 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

t_light		light(t_tup position, t_tup color, float intensity)
{
	t_light l;

	l = malloc(sizeof(struct s_light));
	l->position = position;
	l->color = color;
	l->intensity = intensity;
	return (l);
}

void		light_destroy(void *l_)
{
	t_light l;

	l = (t_light)l_;
	free(l);
}

t_alight	am_light(t_tup color, float ratio)
{
	t_alight al;

	al.color = color;
	al.ratio = ratio;
	return (al);
}

t_tup		reflect(t_tup in, t_tup normal)
{
	return (tup_sub(in, tup_multi(normal, 2 * dotproduct(in, normal))));
}
