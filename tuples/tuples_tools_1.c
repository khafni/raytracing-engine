/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples_tools_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 10:20:05 by khafni            #+#    #+#             */
/*   Updated: 2020/12/08 10:28:46 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

t_tup	tup_add(t_tup t1, t_tup t2)
{
	t_tup sum;

	sum = tuple(0, 0, 0);
	sum.x = t1.x + t2.x;
	sum.y = t1.y + t2.y;
	sum.z = t1.z + t2.z;
	return (sum);
}

t_tup	tup_sub(t_tup v1, t_tup v2)
{
	t_tup diff;

	diff = tuple(0, 0, 0);
	diff.x = v1.x - v2.x;
	diff.y = v1.y - v2.y;
	diff.z = v1.z - v2.z;
	return (diff);
}

t_tup	tup_neg(t_tup v)
{
	t_tup neg;

	neg = tuple(0, 0, 0);
	neg.x = v.x * -1;
	neg.y = v.y * -1;
	neg.z = v.z * -1;
	return (neg);
}

t_tup	tup_multi(t_tup t, float s)
{
	t_tup r;

	r = tuple(0, 0, 0);
	r.x = t.x * s;
	r.y = t.y * s;
	r.z = t.z * s;
	return (r);
}

t_tup	tup_div(t_tup t, float d)
{
	t_tup r;

	r = tuple(0, 0, 0);
	r.x = t.x / d;
	r.y = t.y / d;
	r.z = t.z / d;
	return (r);
}
