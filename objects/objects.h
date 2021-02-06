/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 18:18:26 by khafni            #+#    #+#             */
/*   Updated: 2021/01/23 15:01:13 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	OBJECTS_H 
# define OBJECTS_H 
# include "../CPCA/generic_arrays/garray.h"
# include "../CPCA/generic_arrays/array_heap/arr_heap.h"
# include "../tuples/tuples.h"
# include "../ray.h"
# include "../CPCA/generic_arrays/garray.h"
# include "../CPCA/generic_parrays/garrptr.h"
# include "../matrix/matrices.h"
# include <math.h>

typedef enum {
	SHAPE_TYPE_SPHERE,
	SHAPE_TYPE_PLANE,
	SHAPE_TYPE_SQUARE,
	SHAPE_TYPE_CYLINDER,
	SHAPE_TYPE_TRIANGLE,
	NO_INTERSECTION
}	t_shape_type;



typedef struct s_intersection	t_intersection;

struct			s_intersection
{
	void			*shape;
	double			value;
	t_tup			normal;
	t_tup			p;
	t_shape_type	type;
	t_tup			color;
};

typedef struct s_object	*t_object;

struct			s_object
{
	void			*shape;
	t_shape_type	type;
};
t_intersection	intersect(void *shape, t_shape_type type, t_ray r);
t_object		object(void *shape, t_shape_type type);
void			object_destroy(void *o_);
t_intersection	intersection(void *shape, double value, t_shape_type type);
void			intersections_add(t_array a, t_intersection it);
t_intersection	intersections_get(t_array is, int index);
int				intersections_cmp(void *i1_, void *i2_);
t_intersection	hit(t_array is);
void			set_transform(void *shape, t_shape_type type, t_matrice tr);


/*
**	    ____
**	  .X+.   .
**	.Xx+-.     .
**	XXx++-..
**	XXxx++--..
**	`XXXxx+++--'
**	  `XXXxxx'
**	     ""
** sphere/ray intersection
*/

/*
** sphere object definiton
*/
typedef struct s_sphere	*t_sphere;

struct				s_sphere
{
	t_tup		center;
	float		radius;
	t_tup		color;
};

/*
** sphere object constructor
*/
t_sphere			sphere(t_tup center, int radius, t_tup color);
void				sphere_destroy(void *s_);

typedef struct s_sphere_equat_sol	t_sphere_equat_sol;

struct				s_sphere_equat_sol
{
	float			a;
	float			b;
	float			c;
	float			discriminant;
	float			root1;
	float			root2;
};

t_sphere_equat_sol	sphere_eqt_solver(t_ray ray, t_sphere s);

t_intersection		sphere_intersect(t_ray r, void *s_);

void				set_s_transform(t_sphere *s, t_matrice tr);

t_tup				sh_normal_at(t_sphere sh, t_tup p);

/*
** ray/plane intersection
*/

typedef	struct s_plane *t_plane;

struct				s_plane
{
	t_tup			center;
	t_tup			normal;
	t_tup			color;
};

t_plane				plane(t_tup center, t_tup normal, t_tup color);
void				plane_destroy(void *pl_);
t_intersection		plane_intersect(t_ray r, void *s_);


typedef struct s_triangle *t_triangle;

struct s_triangle
{
	t_tup	pa;
	t_tup	pb;
	t_tup	pc;
	t_tup	normal;
	t_tup	color;
};

t_triangle			triangle(t_tup pa, t_tup pb, t_tup pc, t_tup color);
void				triangle_destroy(void *tr_);
t_intersection		triangle_intersect(t_ray r, void *t_);

typedef struct s_square *t_square;

struct s_square
{
	t_tup	center;
	t_tup	normal;
	double	side_size;
	t_tup	color;
};

t_square			square(t_tup center, t_tup n, double s_size, t_tup col);
void				square_destroy(t_square *sq_);
t_intersection		square_intersect(t_ray r, void *sq_);

/*
**	cylinder
*/

typedef struct s_cylinder *t_cylinder;


struct	s_cylinder
{
	t_tup	center;
	t_tup	normal;
	float	cylind_diameter;
	float	cylind_height;
	t_tup	color;
};

t_cylinder			cylinder(t_tup center, t_tup normal, float cylind_diameter, float cylind_height, t_tup color);
void				cylinder_destroy(void *cy_);
t_intersection		cylinder_intersect(t_ray r, void *cy_);
#endif
