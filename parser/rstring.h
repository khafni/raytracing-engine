/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstring.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 16:09:07 by khafni            #+#    #+#             */
/*   Updated: 2021/02/02 15:48:28 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RSTRING_H
# define RSTRING_H
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_rstr *t_rstr;

struct	s_rstr
{
	char	*data;
	int		alloc;
	int		len;
};

t_rstr	rstr_create (int alloc);
void	rstr_destroy (t_rstr rs);
void	rstr_set (t_rstr rs, size_t index, char value);
void	rstr_add (t_rstr rs, char value);
void	rstr_clear(t_rstr rs);
void	rstr_set(t_rstr rs, size_t index, char value);

#endif
