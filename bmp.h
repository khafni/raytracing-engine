/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 11:49:11 by khafni            #+#    #+#             */
/*   Updated: 2020/12/17 16:50:44 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_H
# define BMP_H

/*
**           _____                    _____                    _____
**          /\    \                  /\    \                  /\    \
**         /::\    \                /::\____\                /::\    \
**        /::::\    \              /::::|   |               /::::\    \
**       /::::::\    \            /:::::|   |              /::::::\    \
**      /:::/\:::\    \          /::::::|   |             /:::/\:::\    \
**     /:::/__\:::\    \        /:::/|::|   |            /:::/__\:::\    \
**    /::::\   \:::\    \      /:::/ |::|   |           /::::\   \:::\    \
**   /::::::\   \:::\    \    /:::/  |::|___|______    /::::::\   \:::\    \
**  /:::/\:::\   \:::\ ___\  /:::/   |::::::::\    \  /:::/\:::\   \:::\____\
** /:::/__\:::\   \:::|    |/:::/    |:::::::::\____\/:::/  \:::\   \:::|    |
** \:::\   \:::\  /:::|____|\::/    / ~~~~~/:::/    /\::/    \:::\  /:::|____|
**  \:::\   \:::\/:::/    /  \/____/      /:::/    /  \/_____/\:::\/:::/    /
**   \:::\   \::::::/    /               /:::/    /            \::::::/    /
**    \:::\   \::::/    /               /:::/    /              \::::/    /
**     \:::\  /:::/    /               /:::/    /                \::/____/
**      \:::\/:::/    /               /:::/    /                  ~~
**       \::::::/    /               /:::/    /
**        \::::/    /               /:::/    /
**         \::/____/                \::/    /
**          ~~                       \/____/
** a writable RGB pixels canvas that doesn't need any external
** graphics library/openGL context by writing directly into a bitmap image for
** rendering purposes
*/

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdint.h>
# include "color.h"

/*
** the pixel canvas is just a 2D array
** that we set every cell in it with pixel value
*/
typedef struct s_bmp	t_bmp;

struct	s_bmp
{
	int		width;
	int		height;
	int		padded_width;
	int		bitmap_size;
	char	*pixels;
};

/*
** a function that writes/overwrites a whole filled 2D pixels' array
** into a bmp image (t_bmp is just an abstraction above a char 2D array
** with more infos about it)
*/
void	write_bmp(char *filename, t_bmp *rgb);

/*
**	function that returns an empty dynamically allocated pixels 2D array
*/

t_bmp	create_pixels_array(int width, int height);

/*
** set a pixels array cell with a value
*/

void	set_bmp_pixel(t_bmp *bmp, int x, int y, int value);
#endif
