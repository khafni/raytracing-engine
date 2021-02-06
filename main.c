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
	t_matrice t = view_transform(point(0, 10, 0), vector(0 , -1, 0), vector(0, -1, 0)); 
	t_world w = empty_world();
	t_camera c = camera(500, 500, M_PI / 2.0, t);
	//to = tuple(0, 1, 0);
	/* matrix_4x4_debug(c.transform); */
	arrptr_add(w->objects, object(sphere(tuple(0, 0, 0), 1, tuple(255, 0, 255)), SHAPE_TYPE_SPHERE));
	arrptr_add(w->lights, light(tuple(5, 0, 0), tuple(255, 255, 255), 1));
    arrptr_add(w->lights, light(tuple(-5, 0, 0), tuple(255, 255, 255), 1));
	w->ambient = am_light(tuple(255, 255, 255), .1);
	//arrptr_add(w->cameras, c);

	t_bmp b = render(c, w);
	write_bmp("cy.bmp", &b);
	/* t_matrice tr = translation(5, -3, 2);
	t_tup p = matrix_4x4_multiply_by_tuple(inverse(tr), point(-3, 4, 5));	 */
    camera_destroy(c);
	world_destroy(w);

	return (0);
}