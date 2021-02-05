/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garrptr.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 00:23:00 by khafni            #+#    #+#             */
/*   Updated: 2020/12/23 15:09:05 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** dynamic array of void pointers module because why not
*/

#ifndef GARRPTR_H
# define GARRPTR_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "../memory_tools.h"
# define GPARRAY_DEFAULT_SIZE 64

typedef void	(*t_destructor)(void *obj);
typedef struct s_arrptr *t_arrptr;
typedef int	(*t_compar)(const void *, const void*);

struct			s_arrptr
{
	void			**data;
	int				len;
	int				alloc;
	t_destructor	obj_des;
	t_compar		obj_cmp;
};
/*
** constructor of the array with a 64 case by default size
*/
t_arrptr		empty_arrptr_create(t_destructor obj_des);

/*
** constructor of the array with a specific size
*/

t_arrptr		empty_arrptr_create_size(int size, t_destructor obj_des);

/*
** distructor of the array
*/

void			arrptr_destroy(t_arrptr a);

/*
** different methods for the dynamic void pointers array
*/

/*
**	get a specific cell of the array
*/

void			*arrptr_get(t_arrptr a, int index);

/*
**	set a specific cell of the array
*/

void			arrptr_set(t_arrptr a, int index, void *obj);

/*
**	add an element to the array even if the array if full
** (c++ vectors push back method)
*/
void			arrptr_add(t_arrptr a, void *obj);
#endif
