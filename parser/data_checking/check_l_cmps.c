/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_l_cmps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 08:45:57 by khafni            #+#    #+#             */
/*   Updated: 2021/02/11 10:30:19 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

int		check_n_paramters(char **element, int n)
{
	int i;

	i = 0;
	while (element[i])
		i++;
	if (i == n)
		return (1);
	else
		return (0);
}

int		check_number(char *n_str)
{
	int i;

	i = 0;
	if (!ft_isdigit(n_str[0]) && n_str[0] != '-')
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

int		check_num_of_commas(char *number)
{
	int		n;
	char	*p;

	n = 0;
	p = number;
	while (*p)
	{
		if (*(p) == ',')
			n++;
		p++;
	}
	if (n != 2)
		return (0);
	return (1);
}

int		check_num_of_m(const char *number)
{
	int n;

	n = 0;
	while (*number)
	{
		if (*number == '-')
			n++;
		number++;
	}
	if (n > 1)
		return (0);
	return (1);
}
