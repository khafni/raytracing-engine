/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 23:11:59 by khafni            #+#    #+#             */
/*   Updated: 2021/02/12 12:09:25 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper_functions.h"

int		ft_atoi(const char *str)
{
	int				i;
	long long		nb;
	int				neg;

	i = 0;
	nb = 0;
	neg = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '0')
		i++;
	if (ft_strlen(str + i) > 8)
		return (-1);
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		nb = nb * 10 + str[i] - '0';
		if (nb > 9223372036854775807)
			return (neg < 0 ? 0 : -1);
		i++;
	}
	return (neg * nb);
}
