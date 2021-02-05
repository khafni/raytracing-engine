/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 16:52:36 by khafni            #+#    #+#             */
/*   Updated: 2021/01/06 16:52:47 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

float	maxnum(float n1, float n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}

float	minnum(float n1, float n2)
{
	if (n1 < n2)
		return (n1);
	return (n2);
}
