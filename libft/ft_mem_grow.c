/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_grow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 15:33:07 by khafni            #+#    #+#             */
/*   Updated: 2021/02/02 15:50:30 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_mem_grow(void *addr, size_t old_size, size_t new_size)
{
	void *tmp;

	tmp = malloc(new_size);
	ft_memcpy(tmp, addr, old_size);
	free(addr);
	return (tmp);
}
