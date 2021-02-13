/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 23:11:59 by khafni            #+#    #+#             */
/*   Updated: 2021/02/13 16:52:13 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper_functions.h"

int		ft_atoi(const char *str)
{
	int				i;
	int				nb;
	int				neg;

	i = 0;
	nb = 0;
	neg = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' '
	|| str[i] == '-' || str[i] == '+' || str[i] == '0')
	{
		neg = ((str[i] == '-') ? -1 : 1);
		i++;
	}
	if (ft_strlen(str + i) > 8)
		return (1111111111);
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	return (neg * nb);
}
