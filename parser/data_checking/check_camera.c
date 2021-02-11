/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 15:10:17 by khafni            #+#    #+#             */
/*   Updated: 2021/02/11 11:53:42 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

void	check_fow(char *fow, t_sxb sxb)
{
	double ratio;

	if (!check_f_number(fow))
	{
		sxb_set_error(sxb, "Error\nfield of view is not a float");
		return ;
	}
	ratio = ft_atof(fow);
	if (ratio < 0 || ratio > 180)
		sxb_set_error(sxb, "Error\nfow  wrong value");
}

void	check_camera(t_sxb sxb)
{
	char	**cam_cmps;

	cam_cmps = ft_split(sxb->f->str_buff->data, ' ');
	if (!check_n_paramters(cam_cmps, 4))
	{
		sxb_set_error(sxb, "Error\nwrong number of parameters for cam");
		free_split(cam_cmps);
		return ;
	}
	check_position(cam_cmps[1], sxb);
	check_normal(cam_cmps[2], sxb);
	check_fow(cam_cmps[3], sxb);
	sxb->cameras_number++;
	free_split(cam_cmps);
}
