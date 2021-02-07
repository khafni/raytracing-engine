/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_l_cmps2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 08:48:18 by khafni            #+#    #+#             */
/*   Updated: 2021/02/02 15:24:12 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

void	check_dot_rt(char *dotrt)
{
	if (!reverse_check(dotrt, ".rt"))
	{
		ft_putstr_fd("Error\nnot a .rt file!", 2);
		exit(EXIT_FAILURE);
	}
}

void	check_position(char *normal_vec, t_sxb sxb)
{
	char	**xyz;
	int		i;

	i = 0;
	xyz = ft_split(normal_vec, ',');
	while (xyz[i])
	{
		if (!check_f_number(xyz[i]))
		{
			sxb_set_error(sxb, "Error\npositon's vector bad formatted");
			free_split(xyz);
			return ;
		}
		i++;
	}
	if (!check_num_of_commas(normal_vec) || i != 3)
	{
		sxb_set_error(sxb, "Error\nposition's vector bad formatted");
		free_split(xyz);
		return ;
	}
	free_split(xyz);
}
