/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 17:51:40 by khafni            #+#    #+#             */
/*   Updated: 2021/02/13 17:53:52 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper_functions.h"

int			atof_digs_coun(const char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '.')
	{
		i++;
	}
	return (i);
}

void		atof_helper(const char *str, double *val)
{
	int		i;
	double	power;

	i = 0;
	power = 1.0;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		*val = *val * 10 + str[i] - '0';
		power *= 10;
		i++;
	}
	*val = *val / power;
}

double		ft_atof(const char *str)
{
	int				i;
	double			val;
	int				neg;

	i = 0;
	val = 0;
	neg = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' '
	|| str[i] == '-' || str[i] == '+' || str[i] == '0')
	{
		neg = ((str[i] == '-') ? -1 : 1);
		i++;
	}
	if (atof_digs_coun(str + i) > 8)
		return (1111111111);
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		val = val * 10 + str[i] - '0';
		i++;
	}
	if (str[i] == '.')
		i++;
	atof_helper(str + i, &val);
	val *= neg;
	return (val);
}
