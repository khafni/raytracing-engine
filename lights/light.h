/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 12:10:20 by khafni            #+#    #+#             */
/*   Updated: 2021/02/10 15:51:31 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H
# include "../tuples/tuples.h"
# include "../tools.h"
# include "../CPCA/generic_arrays/garray.h"
# include "../objects/objects.h"

typedef struct s_light	*t_light;

struct		s_light
{
	t_tup position;
	t_tup color;
	float intensity;
};

t_light		light(t_tup position, t_tup color, float intensity);
void		light_destroy(void *l_);

/*
** ambient lighting
*/

typedef struct s_alight	t_alight;

struct		s_alight
{
	t_tup color;
	float ratio;
};

typedef struct s_material	t_material;

struct		s_material
{
	t_tup color;
	float ratio;
};

t_alight	am_light(t_tup color, float ratio);

t_tup		reflect(t_tup in, t_tup normal);
#endif
