/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 19:18:26 by khafni            #+#    #+#             */
/*   Updated: 2021/02/01 11:55:37 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H
# define DEFAULT_BUFFER_SIZE 4000
# include "rstring.h"
# include <unistd.h>
# include <fcntl.h>

typedef struct s_file	*t_file;

struct	s_file
{
	int		fd;
	char	*buffer;
	int		len;
	int		cursor;
	t_rstr	str_buff;
	int		reading_state;
	int		is_empty;
};

t_file	file(int fd);
void	file_destroy(t_file f);
int		file_read_char(t_file f);
void	file_read_line(t_file f);
#endif
