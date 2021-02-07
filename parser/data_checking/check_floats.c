/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_floats.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 14:26:43 by khafni            #+#    #+#             */
/*   Updated: 2021/02/02 15:24:02 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

int		ft_is_digit_f(int c)
{
	if ((c >= '0' && c <= '9') || c == '.' || c == '-')
		return (1);
	return (0);
}

int		check_f_number(char *number)
{
	int i;

	i = 0;
	while (number[i])
	{
		if (!ft_is_digit_f(number[i]))
		{
			return (0);
		}
		i++;
	}
	if (!check_num_of_dots(number) || !check_num_of_m(number))
	{
		return (0);
	}
	return (1);
}

int		check_num_of_dots(const char *number)
{
	int n;

	n = 0;
	while (*(number++))
	{
		if (*number == '.')
			n++;
	}
	if (n > 1)
		return (0);
	return (1);
}
