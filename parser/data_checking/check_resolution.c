/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_resolution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 14:40:05 by khafni            #+#    #+#             */
/*   Updated: 2021/02/13 17:11:54 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

int		check_number_r(char *n_str)
{
	int i;

	i = 0;
	if (!ft_isdigit(n_str[0]))
		return (0);
	i++;
	while (n_str[i])
	{
		if (!ft_isdigit(n_str[i]))
			return (0);
		i++;
	}
	return (1);
}

int		check_resolution_helper(char **r_es, t_sxb sxb)
{
	int i;

	if (!check_n_paramters(r_es, 3))
	{
		sxb_set_error(sxb, "Error\nwrong number of parameters for resoluton");
		free_split(r_es);
		return (0);
	}
	i = 1;
	while (r_es[i])
	{
		if (!check_number_r(r_es[i]))
		{
			sxb_set_error(sxb, "Error\nresolution bad format");
			free_split(r_es);
			return (0);
		}
		i++;
	}
	return (1);
}

void	check_resolution(t_sxb sxb)
{
	char	**r_es;

	if (sxb->r > 0)
	{
		sxb_set_error(sxb, "Error\nresolution already exists in the .rt file");
		return ;
	}
	r_es = ft_split(sxb->f->str_buff->data, ' ');
	if (!check_resolution_helper(r_es, sxb))
		return ;
	if (!ft_atoi(r_es[1]))
		sxb_set_error(sxb, "Error\nwidth is null");
	if (!ft_atoi(r_es[2]))
		sxb_set_error(sxb, "Error\nheight is null");
	sxb->r += 1;
	free_split(r_es);
}
