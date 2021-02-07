/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 17:32:19 by khafni            #+#    #+#             */
/*   Updated: 2021/02/02 15:23:40 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

void	check_ambient(t_sxb sxb)
{
	char **a_es;

	if (sxb->a > 0)
	{
		sxb_set_error(sxb
		, "Error\nambient light already exists more than once");
		return ;
	}
	a_es = ft_split(sxb->f->str_buff->data, ' ');
	if (!check_n_paramters(a_es, 3))
	{
		sxb_set_error(sxb
		, "Error\nwrong number of parameters for ambient light");
		return ;
	}
	check_light_ratio(*(a_es + 1), sxb);
	check_color(*(a_es + 2), sxb);
	free_split(a_es);
}
