/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 08:38:41 by khafni            #+#    #+#             */
/*   Updated: 2021/02/15 15:55:14 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

void	check_arguments(int argc, char **argv)
{
	(void)argc;
	if (argc < 2 || argc > 3)
	{
		ft_putstr_fd("Error\nwrong number of arguments!", 2);
		exit(EXIT_FAILURE);
	}
	check_dot_rt(argv[1]);
	if (argc == 3)
	{
		if (strcmp(argv[2], "--save"))
		{
			ft_putstr_fd("Error\nusage: ./miniRT *.rt\n", 2);
			ft_putstr_fd("or ./minirt *rt --save", 2);
			exit(EXIT_FAILURE);
		}
	}
}

void	check_rt(int argc, char **argv)
{
	int	fd;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error\n");
		close(fd);
		exit(EXIT_FAILURE);
	}
}
