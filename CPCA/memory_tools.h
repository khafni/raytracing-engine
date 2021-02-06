/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_tools.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 16:34:00 by khafni            #+#    #+#             */
/*   Updated: 2020/12/28 16:48:25 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_TOOLS_H
# define MEMORY_TOOLS_H
# include <string.h>
# include <stdlib.h>

/*
** copy n bytes of memory from src memory address to
** dst memory address
*/

void	*memory_copy(void *dst, const void *src, size_t n);

/*
**	grow allocated memory from old_size bytes size to new_size
**	bytes size
*/
void	*memory_grow(void *address, size_t old_size, size_t new_size);

/*
**  swapping two void pointers addresses
*/

void	vp_swap(void **v1, void **v2);

/*
**  swapping two continuous areas of memory that have the same size;
*/

void	memory_swap(void *a1_, void *a2_, size_t size);

#endif
