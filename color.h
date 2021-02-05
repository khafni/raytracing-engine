/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 12:40:18 by khafni            #+#    #+#             */
/*   Updated: 2021/01/15 15:00:37 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H
# include "tuples/tuples.h"

/*
** storing the red and green and blue values
** of a pixel in one int value
** using bitshifting
*/
int		create_color(t_tup color);

/*
** getting the red value out of the pixel int color value
*/

int		get_r(int color);

/*
** getting the green value out of the pixel int color value
*/

int		get_g(int color);

/*
** getting the blue value out of the pixel int color value
*/

int		get_b(int color);
#endif
