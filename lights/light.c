/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 17:07:15 by khafni            #+#    #+#             */
/*   Updated: 2021/01/18 17:13:17 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

t_light		light(t_tup position, t_tup color, float intensity)
{
	t_light l;

	l.position = position;
	l.color = color;
	l.intensity = intensity;
	return (l);
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

