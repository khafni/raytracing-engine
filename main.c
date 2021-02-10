/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 15:35:28 by khafni            #+#    #+#             */
/*   Updated: 2021/02/10 15:37:27 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "matrix/matrices.h"
#include "camera/view_transform.h"
#include "world/world.h"
#include "render.h"
#include "parser/parser.h"

int		main(int argc, char **argv)
{
	t_world	w;

	parse_syntax(argc, argv);
	w = get_data_from_rt(argc, argv);
	render(argc, argv, w);
	return (0);
}
