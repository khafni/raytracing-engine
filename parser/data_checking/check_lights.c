/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lights.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 14:28:49 by khafni            #+#    #+#             */
/*   Updated: 2021/02/02 15:24:35 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

void	check_light_ratio(char *ratio, t_sxb sxb)
{
	double rat;

	if (!check_f_number(ratio))
	{
		sxb_set_error(sxb, "Error\nambient_ratio is not a float");
		return ;
	}
	rat = ft_atof(ratio);
	if (rat < 0 || rat > 1.0)
	{
		sxb_set_error(sxb, "Error\nlight ratio wrong value");
		return ;
	}
}

void	check_light(t_sxb sxb)
{
	char	**light_cmps;

	light_cmps = ft_split(sxb->f->str_buff->data, ' ');
	if (!check_n_paramters(light_cmps, 4))
	{
		sxb_set_error(sxb, "Error\nwrong number of parameters for light");
		free_split(light_cmps);
		return ;
	}
	check_position(light_cmps[1], sxb);
	check_light_ratio(light_cmps[2], sxb);
	check_color(light_cmps[3], sxb);
	free_split(light_cmps);
}
