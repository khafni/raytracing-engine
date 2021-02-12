/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 07:41:04 by khafni            #+#    #+#             */
/*   Updated: 2021/02/12 16:39:38 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

int		is_shape(char *word)
{
	if (!ft_strcmp(word, "sp"))
		return (0);
	else if (!ft_strcmp(word, "pl"))
		return (0);
	else if (!ft_strcmp(word, "sq"))
		return (0);
	else if (!ft_strcmp(word, "cy"))
		return (0);
	else if (!ft_strcmp(word, "tr"))
		return (0);
	return (1);
}

void	check_shapes(char *word, t_sxb sxb)
{
	if (!ft_strcmp(word, "sp"))
		check_sphere(sxb);
	else if (!ft_strcmp(word, "pl"))
		check_plane(sxb);
	else if (!ft_strcmp(word, "sq"))
		check_square(sxb);
	else if (!ft_strcmp(word, "cy"))
		check_cylinder(sxb);
	else if (!ft_strcmp(word, "tr"))
		check_triangle(sxb);
}

void	check_line_syntax(t_sxb sxb)
{
	char **words;

	words = ft_split(sxb->f->str_buff->data, ' ');
	if (words[0] == NULL)
	{
		if (sxb->f->str_buff->len && sxb->f->str_buff->data[0] == ' ')
			sxb_set_error(sxb, "Error\nspace at the beginning of a line");
		free_split(words);
		return ;
	}
	if (!ft_strcmp(words[0], "c"))
		check_camera(sxb);
	else if (!ft_strcmp(words[0], "R"))
		check_resolution(sxb);
	else if (!ft_strcmp(words[0], "A"))
		check_ambient(sxb);
	else if (!ft_strcmp(words[0], "l"))
		check_light(sxb);
	else if (!is_shape(words[0]))
		check_shapes(words[0], sxb);
	else
		sxb_set_error(sxb, "Error\n.rt file ill formated");
	free_split(words);
}

void	check_rt_file_conf(char *file_name, t_sxb sxb)
{
	sxb->f = file(open(file_name, O_RDONLY));
	sxb->fd = sxb->f->fd;
	sxb->is_error = 0;
	sxb->r = 0;
	sxb->a = 0;
	while (sxb->f->reading_state > 0)
	{
		file_read_line(sxb->f);
		check_line_syntax(sxb);
	}
	if (sxb->f->is_empty)
	{
		ft_putstr_fd("Error\n.rt empty", 2);
		sxb_destroy(sxb);
		exit(EXIT_FAILURE);
	}
}

void	parse_syntax(int argc, char **argv)
{
	t_sxb sxb;

	sxb = sxb_create();
	check_arguments(argc, argv);
	check_rt(argc, argv);
	check_rt_file_conf(argv[1], sxb);
	if (!sxb->r)
		sxb_set_error(sxb, "Error\nno resolution specified in the .rt");
	else if (!sxb->cameras_number)
		sxb_set_error(sxb, "Error\n0 camera specified in the .rt");
	else if (!sxb->does_ambient_exist || sxb->does_ambient_exist > 1)
		sxb_set_error(sxb, "Error\nno ambient light specified in the .rt");
	if (sxb->is_error)
	{
		ft_putstr_fd(sxb->error_message, 2);
		sxb_destroy(sxb);
		exit(EXIT_FAILURE);
	}
	sxb_destroy(sxb);
}
