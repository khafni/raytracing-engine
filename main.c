#include <stdio.h>
#include "matrix/matrices.h"
#include "camera/view_transform.h"
#include "world/world.h"
#include "render.h"

void tup_debug(t_tup t)
{
	printf("%f %f %f\n", t.x, t.y, t.z);
}

void matrix_4x4_debug(t_matrice M)
{
    int i;
    int j;

    j = 0;
    printf("\n-----------------------------------------------\n");
    while (j < 4)
    {
        i = 0;
        printf(" | ");
        while (i < 4)
        {
            printf("%f", get_cell(M, i, j));
            printf(" | ");
            i++;
        }
        printf("\n-----------------------------------------------\n");
        j++;
    }
}

int main(void)
{
	t_sphere s = sphere(tuple(0, 5, 7), 1, tuple(255, 0, 0));	
	t_sphere s1 = sphere(tuple(-8, 5, -3), 1, tuple(255, 0, 255));
	t_sphere s2 = sphere(tuple(8, 5, -3), 1, tuple(0, 255, 0));
	t_sphere s3 = sphere(tuple(0, 5, 0), 1, tuple(255, 255, 0));
	t_plane p = plane(tuple(0, 0, 0), tuple(0, 1, 0), tuple(128, 128, 128));
	t_triangle tr = triangle(tuple(-8, 5, -3), tuple(0, 5, 7), tuple(8, 5, -3), tuple(0, 0, 255));
	t_square sq = square(tuple(0, 3, 0), tuple(0, 1, 0), 15, tuple(0, 255, 255));
	t_cylinder cy = cylinder(tuple(0, 10, 0), tuple(0,1,0), 3, 100, tuple(255, 0, 0));

	t_object obj = object(&s, SHAPE_TYPE_SPHERE);
	t_object obj1 = object(&s1, SHAPE_TYPE_SPHERE);
	t_object obj2 = object(&p, SHAPE_TYPE_PLANE);
	t_object obj3 = object(&tr, SHAPE_TYPE_TRIANGLE);
	t_object obj4 = object(&s2, SHAPE_TYPE_SPHERE);
	t_object obj5 = object(&sq, SHAPE_TYPE_SQUARE);
	t_object obj6 = object(&s3, SHAPE_TYPE_SPHERE);
	t_object obj7 = object(&cy, SHAPE_TYPE_CYLINDER);
	t_light l = light(tuple(0, 50, 0), tuple(255, 255, 255), 1);
	t_matrice t = view_transform(point(0, 30, 0), vector(0 , -1, 0), vector(0, -1, 0)); 
	t_world w = empty_world();
	garr_add(w.objects, &obj);
	garr_add(w.objects, &obj1);
	garr_add(w.objects, &obj2);
	garr_add(w.objects, &obj3);
	garr_add(w.objects, &obj4);
	garr_add(w.objects, &obj5);
	//garr_add(w.objects, &obj6);
	garr_add(w.objects, &obj7);
	garr_add(w.lights, &l);
	w.ambient = am_light(tuple(255, 255, 255), .1);

	t_camera c = camera(1500, 1500, M_PI / 2.0, t);
	c.to = tuple(0, 1, 0);
	/* matrix_4x4_debug(c.transform); */
	t_bmp b = render(c, w);
	write_bmp("cy.bmp", &b);
	/* t_matrice tr = translation(5, -3, 2);
	t_tup p = matrix_4x4_multiply_by_tuple(inverse(tr), point(-3, 4, 5));	 */
	

	return (0);
}