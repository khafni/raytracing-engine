/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_normal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 15:56:18 by khafni            #+#    #+#             */
/*   Updated: 2021/02/10 15:53:38 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

void	is_vec_normalized(double x, double y, double z, t_sxb sxb)
{
	double m;

	m = 0;
	m = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
	if (m > 1)
	{
		sxb->is_error = 1;
		sxb->error_message = ft_strdup("Error\nnormal vector not normalized!");
		return ;
	}
}

void	check_normal(char *normal_vec, t_sxb sxb)
{
	char	**xyz;
	int		i;

	i = 0;
	xyz = ft_split(normal_vec, ',');
	while (xyz[i])
	{
		if (!check_f_number(xyz[i]))
		{
			sxb_set_error(sxb, "Error\nnormal vector bad formatted");
			free_split(xyz);
			return ;
		}
		i++;
	}
	if (!check_num_of_commas(normal_vec) || i != 3)
	{
		sxb_set_error(sxb, "Error\nnormal vector bad formatted");
		free_split(xyz);
		return ;
	}
	free_split(xyz);
}
