/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 12:21:28 by khafni            #+#    #+#             */
/*   Updated: 2020/12/08 13:05:24 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp.h"
#include "bmp.h"
#include <string.h>

int		round4(int x)
{
	return (x % 4 == 0 ? x : x - x % 4 + 4);
}

void	write_bmp(char *filename, t_bmp *rgb)
{
	char	tag[2];
	int		header[13];
	int		fd;

	header[0] = sizeof(tag) + sizeof(header) + rgb->bitmap_size;
	header[1] = 0;
	header[2] = 0x36;
	header[3] = 0x28;
	header[4] = rgb->width;
	header[5] = rgb->height;
	header[6] = 0x180001;
	header[7] = 0;
	header[8] = 0;
	header[9] = 0;
	header[10] = 0;
	header[11] = 0;
	header[12] = 0;
	tag[0] = 'B';
	tag[1] = 'M';
	header[0] = sizeof(tag) + sizeof(header) + rgb->bitmap_size;
	fd = open(filename, O_CREAT | O_WRONLY, S_IRWXU);
	write(fd, &tag, sizeof(tag));
	write(fd, &header, sizeof(header));
	write(fd, rgb->pixels, rgb->bitmap_size);
	close(fd);
}

t_bmp	create_pixels_array(int width, int height)
{
	t_bmp	bmp;
	int		i;

	bmp.width = width;
	bmp.height = height;
	bmp.padded_width = round4(width * 3);
	bmp.bitmap_size = height * bmp.padded_width * 3;
	bmp.pixels = malloc(bmp.bitmap_size * sizeof(char));
	i = 0;
	while (i < bmp.bitmap_size)
	{
		bmp.pixels[i] = 0;
		i++;
	}
	return (bmp);
}

void	set_bmp_pixel(t_bmp *bmp, int x, int y, int value)
{
	int			b;
	int			g;
	int			r;
	int			index;

	b = get_b(value);
	g = get_g(value);
	r = get_r(value);
	index = y * bmp->padded_width + x * 3 + 0;
	bmp->pixels[index] = (char)b;
	index = y * bmp->padded_width + x * 3 + 1;
	bmp->pixels[index] = (char)g;
	index = y * bmp->padded_width + x * 3 + 2;
	bmp->pixels[index] = (char)r;
}
