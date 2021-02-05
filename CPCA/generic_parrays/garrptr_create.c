/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garrptr_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 00:40:42 by khafni            #+#    #+#             */
/*   Updated: 2020/12/24 18:31:52 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garrptr.h"

t_arrptr	empty_arrptr_create_size(int size, t_destructor obj_des)
{
	t_arrptr a;

	a = malloc(sizeof(struct s_arrptr));
	a->len = 0;
	a->alloc = size;
	a->data = malloc(sizeof(void *) * a->alloc);
	a->obj_des = obj_des;
	return (a);
}

t_arrptr	empty_arrptr_create(t_destructor obj_des)
{
	t_arrptr a;

	a = empty_arrptr_create_size(GPARRAY_DEFAULT_SIZE, obj_des);
	return (a);
}

void		arrptr_destroy(t_arrptr a)
{
	int			i;

	i = 0;
	if (a->obj_des != NULL)
	{
		while (i < a->len)
		{
			(*(a->obj_des)) (arrptr_get(a, i));
			i++;
		}
	}
	free(a->data);
	free(a);
}

void		*arrptr_get(t_arrptr a, int index)
{
	return (a->data[index]);
}
