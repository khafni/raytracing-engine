/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_image.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 18:22:58 by khafni            #+#    #+#             */
/*   Updated: 2021/02/07 19:32:51 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_IMAGE_H
#define MLX_IMAGE_H

#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>

typedef struct s_image *t_image;

struct s_image
{
    int height;
    int width;
    void *mlx_ptr;
    void *mlx_img;
    char *data;
    int bits_per_pixel;
    int size_line;
    int endian;
};
/*
** using an mlx image as a canvas`
*/

t_image mlx_create_img(void *mlx_ptr, int width, int height);
void img_set_pixel(t_image img, int x, int y, int value);
void mlx_img_destroy(void *img_);

#endif