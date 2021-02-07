/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:58:43 by khafni            #+#    #+#             */
/*   Updated: 2021/02/07 14:50:57 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

void	add_light(char *line, t_world w)
{
	char		**cmps;
	t_light		l;

	cmps = ft_split(line, ' ');
	l = light(get_tuple(cmps[1]), get_tuple(cmps[3]), ft_atof(cmps[2]));
	arrptr_add(w->lights, l);
	free_split(cmps);
}
