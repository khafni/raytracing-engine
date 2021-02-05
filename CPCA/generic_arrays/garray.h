/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garray.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 01:40:36 by khafni            #+#    #+#             */
/*   Updated: 2020/12/28 14:44:13 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** dynamic generic array of any data type as long as
** you know its size
*/

#ifndef GARRAY_H
# define GARRAY_H
# define GARRAY_DEFAULT_ALLOC 64
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "../memory_tools.h"

typedef void	(*t_destruct)(void *obj);
typedef int		(*t_comp)(void *obj1, void *obj2);
typedef struct s_array	*t_array;

struct			s_array
{
	void		*data;
	int			len;
	int			alloc;
	int			cell_size;
	t_destruct	obj_des;
	t_comp		obj_cmp;
};

/*
** constructor of the array with a 64 case by default size
*/
t_array			empty_garr_64(t_destruct obj_des, int cell_size);

/*
** constructor of the array with a specific size
*/

t_array			empty_garr(int size, t_destruct obj_des, int cell_size);

/*
** distructor of the array
*/

void			garr_destroy(t_array a);

/*
** different methods for the dynamic void pointers array
*/

/*
**	get a specific cell of the array
*/

void			*garr_get(t_array a, int index);

/*
**	set a specific cell of the array
*/

void			garr_set(t_array a, int index, void *obj);

/*
**	add an element to the array even if the array if full
** (c++ vectors push back method)
*/
void			garr_add(t_array a, void *obj);

#endif
