/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 12:45:09 by khafni            #+#    #+#             */
/*   Updated: 2021/01/15 15:02:16 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

int		create_color(t_tup color)
{
	return (((int)color.x << 16) | ((int)color.y << 8) | (int)color.z);
}

int		get_r(int color)
{
	return (color >> 16);
}

int		get_g(int color)
{
	return (color >> 8 & 0xff);
}

int		get_b(int color)
{
	return (color & 0xFF);
}
