/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 17:51:40 by khafni            #+#    #+#             */
/*   Updated: 2021/01/30 11:54:10 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		val = val * 10 + str[i] - '0';
		if (val > 9223372036854775807)
			return (neg < 0 ? 0 : -1);
		i++;
	}
	if (str[i] == '.')
		i++;
	atof_helper(str + i, &val);
	val *= neg;
	return (val);
}
