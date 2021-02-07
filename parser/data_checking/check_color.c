/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 14:36:59 by khafni            #+#    #+#             */
/*   Updated: 2021/02/02 15:23:57 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

void	check_color(char *col, t_sxb sxb)
{
	char	**rgb;
	int		i;

	i = 0;
	rgb = ft_split(col, ',');
	while (rgb[i])
	{
		if (!check_number(rgb[i]))
		{
			sxb_set_error(sxb, "Error\ncolor bad formatted");
			free_split(rgb);
			return ;
		}
		if (ft_atoi(rgb[i]) < 0 || ft_atoi(rgb[i]) > 255)
		{
			sxb_set_error(sxb, "Error\ncolor's component wrong value");
			free_split(rgb);
			return ;
		}
		i++;
	}
	if (!check_num_of_commas(col) || i != 3)
		sxb_set_error(sxb, "Error\ncolor bad formatted");
	free_split(rgb);
}
