/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_ambient.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 16:05:35 by khafni            #+#    #+#             */
/*   Updated: 2021/02/03 16:12:24 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

void	add_ambient(char *line, t_world w)
{
	char		**cmps;
	t_alight	al;

	cmps = ft_split(line, ' ');
	al = am_light(get_tuple(cmps[2]), ft_atof(cmps[1]));
	w->ambient = al;
	free_split(cmps);
}
