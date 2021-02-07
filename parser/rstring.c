/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstring.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 16:56:29 by khafni            #+#    #+#             */
/*   Updated: 2021/02/02 15:51:49 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rstring.h"
#include <stdlib.h>

t_rstr		rstr_create(int alloc)
{
	t_rstr	str;

	str = malloc(sizeof(struct s_rstr));
	str->alloc = alloc;
	str->len = 0;
	str->data = malloc(alloc * sizeof(char));
	return (str);
}

void		rstr_destroy(t_rstr rs)
{
	free(rs->data);
	free(rs);
}

void		rstr_set(t_rstr rs, size_t index, char value)
{
	size_t new_allc;

	new_allc = (1 + 2 * index);
	if ((int)index >= rs->alloc)
	{
		rs->data = ft_mem_grow(rs->data, rs->alloc, new_allc);
		rs->alloc = new_allc;
	}
	if ((int)index >= rs->len)
		rs->len = index + 1;
	*((char*)rs->data + index) = value;
}

void		rstr_add(t_rstr rs, char value)
{
	rstr_set(rs, rs->len, value);
}

void		rstr_clear(t_rstr rs)
{
	int i;

	i = 0;
	while (i < rs->len)
	{
		*((char*)rs->data + i) = '\0';
		i++;
	}
	rs->len = 0;
}
