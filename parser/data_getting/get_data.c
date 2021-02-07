/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 16:41:20 by khafni            #+#    #+#             */
/*   Updated: 2021/02/04 14:39:48 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

void	add_shape(char *line, t_world w)
{
	char **cmps;

	cmps = ft_split(line, ' ');
	if (!ft_strcmp(cmps[0], "sp"))
		get_sphere(line, w);
	else if (!ft_strcmp(cmps[0], "pl"))
		get_plane(line, w);
	else if (!ft_strcmp(cmps[0], "sq"))
		get_square(line, w);
	else if (!ft_strcmp(cmps[0], "cy"))
		get_cylinder(line, w);
	else if (!ft_strcmp(cmps[0], "tr"))
		get_triangle(line, w);
	free_split(cmps);
}

void	parse_line(char *line, t_world w)
{
	char **words;

	words = ft_split(line, ' ');
	if (words[0] == NULL)
	{
		free_split(words);
		return ;
	}
	if (!ft_strcmp(words[0], "R"))
		get_resolution(line, w);
	else if (!ft_strcmp(words[0], "c"))
		add_camera(line, w);
	else if (!ft_strcmp(words[0], "A"))
		add_ambient(line, w);
	else if (!ft_strcmp(words[0], "l"))
		add_light(line, w);
	else if (!is_shape(words[0]))
		add_shape(line, w);
	else
		return ;
	free_split(words);
}

t_tup	get_tuple(char *line)
{
	char	**xyz;
	t_tup	t;

	xyz = ft_split(line, ',');
	t = tuple(ft_atof(xyz[0]), ft_atof(xyz[1]), ft_atof(xyz[2]));
	free_split(xyz);
	return (t);
}

void	fill_world(int argc, char **argv, t_world w)
{
	t_file f;

	(void)argc;
	f = file(open(argv[1], O_RDONLY));
	while (f->reading_state > 0)
	{
		file_read_line(f);
		parse_line(f->str_buff->data, w);
	}
	file_destroy(f);
}

t_world	get_data_from_rt(int argc, char **argv)
{
	t_world w;

	w = empty_world();
	fill_world(argc, argv, w);
	return (w);
}
