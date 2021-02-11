/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 14:39:50 by khafni            #+#    #+#             */
/*   Updated: 2021/02/11 11:52:41 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "file.h"
# include "../helper_functions/helper_functions.h"
# include "math.h"
# include "../world/world.h"

/*
**  __ _  ___  ________ ___ _   _
** (( \\\//||\ ||| || |// \\\\ //
**  \\  )/ ||\\||  ||  ||=|| )X(
** \_))//  || \||  ||  || ||// \\
**   _____  __ ____ _____ ______  __  ___
**  //  ||  ||||   //  || //||||\ || // \\
** ((   ||==||||==((   ||<< ||||\\||(( ___
**  \\__||  ||||___\\__|| \\|||| \|| \\_||
*/

typedef struct s_syntax *t_sxb;

struct	s_syntax
{
	int		fd;
	t_file	f;
	int		r;
	int		a;
	int		cameras_number;
	int		does_ambient_exist;
	char	is_error;
	char	*error_message;
};

t_sxb	sxb_create(void);
void	sxb_set_error(t_sxb sxb, char *error_message);
void	sxb_destroy(t_sxb sxb);
void	parse_syntax(int argc, char **argv);
int		check_n_paramters(char **element, int n);
void	check_dot_rt(char *dotrt);
void	check_arguments(int argc, char **argv);
void	check_rt(int argc, char **argv);
void	check_rt_file_conf(char *file_name, t_sxb sxb);
int		check_num_of_commas(char *number);

/*
** Resolution
*/

int		check_number(char *n_str);
void	check_resolution(t_sxb sxb);

/*
**  ambient light
*/

void	check_ambient (t_sxb sxb);

/*
**  color parser
*/
void	check_color(char *col, t_sxb sxb);

/*
** numbers and floats parser
*/

int		ft_is_digit_f(int c);

int		check_f_number(char	*number);

int		check_num_of_dots(const char *number);

int		check_num_of_m(const char *number);

/*
**  normal  vectors
*/

void	check_normal(char *normal, t_sxb sxb);

/*
**	position of objects/lights/cameras
*/

void	check_position(char *pos, t_sxb sxb);

/*
** lights
*/

void	check_light(t_sxb sxb);
void	check_light_ratio(char *ratio, t_sxb sxb);

/*
**	Camera
*/

void	check_camera(t_sxb sxb);

/*
** geometric objects synatx analysis
*/
int		is_shape(char *word);
void	check_sphere(t_sxb sxb);
void	check_plane(t_sxb sxb);
void	check_square(t_sxb sxb);
void	check_cylinder(t_sxb sxb);
void	check_triangle(t_sxb sxb);
/*
**         _         _
**        | |       | |
**      __| |  __ _ | |_  __ _
**     / _` | / _` || __|/ _` |
**    | (_| || (_| || |_| (_| | _
**     \__,_| \__,_| \__|\__,_|(_)
**     _ __    __ _  _ __  ___  _  _ __    __ _
**    | '_ \  / _` || '__|/ __|| || '_ \  / _` |
**    | |_) || (_| || |   \__ \| || | | || (_| |
**    | .__/  \__,_||_|   |___/|_||_| |_| \__, |
**    | |                                  __/ |
**    |_|                                 |___/
*/

t_tup	get_tuple(char *line);
void	get_sphere(char *line, t_world w);
void	get_plane(char *line, t_world w);
void	get_square(char *line, t_world w);
void	get_cylinder(char *line, t_world w);
void	get_triangle(char *line, t_world w);
void	add_camera(char *line, t_world w);
void	get_resolution(char *line, t_world w);
void	add_ambient(char *line, t_world w);
void	add_light(char *line, t_world w);
void	add_shape(char *line, t_world w);
t_world	get_data_from_rt(int argc, char **argv);
#endif
