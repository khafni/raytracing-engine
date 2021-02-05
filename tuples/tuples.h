/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 10:17:35 by khafni            #+#    #+#             */
/*   Updated: 2021/01/18 11:27:24 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLES_H
# define TUPLES_H

# include <math.h>

/*
**	a tuple is just a 4 elements ordered pair of doubles
**	that can be used to represent points or vectors
*/
typedef struct s_tup	t_tup;

# define VECTOR  0
# define POINT 1
# define HEAP 0
# define STACK 1

struct	s_tup
{
	double	x;
	double	y;
	double	z;
	char	is_point_or_vector;
};

/*
** |||||||||||||||||||||||||||||||||||||||||||||||||
** ||                                             ||
** ||      non dynimically allocated tuples       ||
** ||                                             ||
** |||||||||||||||||||||||||||||||||||||||||||||||||
*/

t_tup	tuple(float x, float y, float z);

t_tup	point(float x, float y, float z);

t_tup	vector(float x, float y, float z);
/*
** adding two 3 elements vectors
*/
t_tup	tup_add(t_tup t1, t_tup t2);

/*
** substracting two t_vect3s
*/
t_tup	tup_sub(t_tup t1, t_tup t2);

/*
** negating a t_tuple
*/
t_tup	tup_neg(t_tup v);

/*
** scalar multiplication
*/
t_tup	tup_multi(t_tup t, float s);

/*
** scalar division
*/
t_tup	tup_div(t_tup t, float d);

/*
** magnitude of a vector
*/
float	tup_mag(t_tup vec);

/*
** normalize a vector
*/
t_tup	tup_norm(t_tup vec);

/*
** dot product of v1 and v2
*/
float	dotproduct(t_tup v1, t_tup v2);

/*
** cross product of v1 and v2
*/
t_tup	crossproduct(t_tup v1, t_tup v2);

/*
** copy tuple src to tuple dst
*/

void	tup_copy(t_tup *src, t_tup *dst);

int		tup_eq(t_tup t1, t_tup t2);
#endif
