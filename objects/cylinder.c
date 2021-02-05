/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 14:58:06 by khafni            #+#    #+#             */
/*   Updated: 2021/01/24 17:30:01 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_cylinder	cylinder(t_tup center, t_tup normal, float cylind_diameter, float cylind_height, t_tup color)
{
	t_cylinder  cy;

	cy.center = center;
	cy.normal = normal;
	cy.cylind_diameter = cylind_diameter;
	cy.cylind_height = cylind_diameter;
	cy.color = color;
	return (cy);
}

/* t_intersection		cylinder_intersect(t_ray r, void *cy_); */