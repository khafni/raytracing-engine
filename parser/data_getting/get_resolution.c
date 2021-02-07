/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_resolution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 10:48:59 by khafni            #+#    #+#             */
/*   Updated: 2021/02/07 15:54:28 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

void	get_resolution(char *line, t_world w)
{
	char	**r_es;

	r_es = ft_split(line, ' ');
	w->r_width = ft_atoi(r_es[1]);
	w->r_height = ft_atoi(r_es[2]);
	if (w->r_height == -1 || w->r_height > 1440)
		w->r_height = 1440;
	if (w->r_width == -1 || w->r_width > 2560)
		w->r_width = 2560;
	free_split(r_es);
}
