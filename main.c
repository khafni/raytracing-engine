#include <stdio.h>
#include "matrix/matrices.h"
#include "camera/view_transform.h"
#include "world/world.h"
#include "render.h"
#include "parser/parser.h"

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

/* int main(int argc, char **argv)
{
    parse_syntax(argc, argv);
	t_world w = get_data_from_rt(argc, argv);
	//to = tuple(0, 1, 0);
	matrix_4x4_debug(c.transform);
	t_bmp b = render(arrptr_get(w->cameras, 0), w);
	write_bmp("cy.bmp", &b);
	t_matrice tr = translation(5, -3, 2);
	t_tup p = matrix_4x4_multiply_by_tuple(inverse(tr), point(-3, 4, 5));	
    //camera_destroy(c);
	world_destroy(w);

	return (0);
} */

int main(int argc, char **argv)
{
    parse_syntax(argc, argv);
    get_data_from_rt(argc, argv);
	t_matrice t = view_transform(point(0, 10, 0), vector(0 , -1, 0), vector(0, -1, 0)); 
	t_world w = get_data_from_rt(argc, argv);
	t_camera c = arrptr_get(w->cameras, 0);
    //tup_debug(c->to);
    //printf("%d", c->hsize);
	//to = tuple(0, 1, 0);
	/* arrptr_add(w->objects, object(sphere(tuple(0, 0, 0), 1, tuple(255, 0, 255)), SHAPE_TYPE_SPHERE));
	arrptr_add(w->lights, light(tuple(5, 0, 0), tuple(255, 255, 255), 1));
    arrptr_add(w->lights, light(tuple(-5, 0, 0), tuple(255, 255, 255), 1));
	w->ambient = am_light(tuple(255, 255, 255), .1);
	//arrptr_add(w->cameras, c);*/

    //arrptr_add(w->objects, object(sphere(tuple(0, 0, 0), 1, tuple(255, 0, 255)), SHAPE_TYPE_SPHERE));
	render_bmp(c, w);
    /* void *mlx_p = mlx_init();
    void *mlx_window = mlx_new_window(mlx_p, w->r_width, w->r_height, "window");

    t_image img = render_mlx_image(c, w, mlx_p);
    mlx_put_image_to_window(mlx_p, mlx_window, img->mlx_img, 0, 0);
    mlx_loop(mlx_p);  */
    //camera_destroy(c);
    world_destroy(w);

	return (0);
}