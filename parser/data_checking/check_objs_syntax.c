/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_objs_syntax.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 15:28:21 by khafni            #+#    #+#             */
/*   Updated: 2021/02/02 15:24:48 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

void	check_sphere(t_sxb sxb)
{
	char	**cmps;

	cmps = ft_split(sxb->f->str_buff->data, ' ');
	if (!check_n_paramters(cmps, 4))
	{
		sxb_set_error(sxb, "Error\nsphere wrong number of parameters");
		free_split(cmps);
		return ;
	}
	check_position(cmps[1], sxb);
	if (!check_f_number(cmps[2]) || ft_atoi(cmps[2]) < 0)
	{
		sxb_set_error(sxb, "Error\nwrong sphere diameter");
		free_split(cmps);
		return ;
	}
	check_color(cmps[3], sxb);
	free_split(cmps);
}

void	check_plane(t_sxb sxb)
{
	char	**cmps;

	cmps = ft_split(sxb->f->str_buff->data, ' ');
	if (!check_n_paramters(cmps, 4))
	{
		sxb_set_error(sxb, "Error\nwrong number of parameters for plane");
		free_split(cmps);
		return ;
	}
	check_position(cmps[1], sxb);
	check_normal(cmps[2], sxb);
	check_color(cmps[3], sxb);
	free_split(cmps);
}

void	check_square(t_sxb sxb)
{
	char	**cmps;

	cmps = ft_split(sxb->f->str_buff->data, ' ');
	if (!check_n_paramters(cmps, 5))
	{
		sxb_set_error(sxb, "Error\nwrong number of parameters for square");
		free_split(cmps);
		return ;
	}
	check_position(cmps[1], sxb);
	check_normal(cmps[2], sxb);
	if (!check_f_number(cmps[3]) || ft_atof(cmps[3]) < 0)
	{
		sxb_set_error(sxb, "Error\nwrong square side size");
		free_split(cmps);
		return ;
	}
	check_color(cmps[4], sxb);
	free_split(cmps);
}

void	check_cylinder(t_sxb sxb)
{
	char	**cmps;

	cmps = ft_split(sxb->f->str_buff->data, ' ');
	if (!check_n_paramters(cmps, 6))
	{
		sxb_set_error(sxb, "Error\nwrong number of parameters for cylinder");
		free_split(cmps);
		return ;
	}
	check_position(cmps[1], sxb);
	check_normal(cmps[2], sxb);
	if (!check_f_number(cmps[3]) || ft_atof(cmps[3]) < 0)
	{
		sxb_set_error(sxb, "Error\nwrong cylinder diameter");
		free_split(cmps);
		return ;
	}
	if (!check_f_number(cmps[4]) || ft_atof(cmps[4]) < 0)
	{
		sxb_set_error(sxb, "Error\nwrong cylinder height");
		free_split(cmps);
		return ;
	}
	check_color(cmps[5], sxb);
	free_split(cmps);
}

void	check_triangle(t_sxb sxb)
{
	char	**cmps;

	cmps = ft_split(sxb->f->str_buff->data, ' ');
	if (!check_n_paramters(cmps, 5))
	{
		sxb_set_error(sxb, "Error\nwrong number of parameters for cylinder");
		free_split(cmps);
		return ;
	}
	check_position(cmps[1], sxb);
	check_position(cmps[2], sxb);
	check_position(cmps[3], sxb);
	check_color(cmps[4], sxb);
	free_split(cmps);
}
