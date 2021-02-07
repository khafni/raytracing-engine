#include "render.h"

t_tup		color_at(t_world w, t_ray r)
{
	t_tup			c;
	t_intersection	xs;
	t_intersection	rs;
	t_tup			eye;

	//t_array a = intersect_world(w, r);
	xs = intersect_world(w, r);
	if (xs.type == NO_INTERSECTION)
		return (tuple(0, 0, 0));	
/* 	if (dotproduct(xs.normal, w.cam->to) < 1)
		xs.normal = tup_neg(xs.normal) */;
	c = lighting(xs, w);
	return (c);
}

void		render_bmp(t_camera c, t_world w)
{
	t_bmp	canvas;
	int		i;
	int		j;
    
    i = 0;
    j = 0;
 	canvas = create_pixels_array(c->hsize, c->vsize);
	while (i < canvas.height)
	{
		j = 0;
		while (j < canvas.width)
		{
			set_bmp_pixel(&canvas, j, i,
            create_color(color_at(w, ray_for_pixel(c, j, i))));
			j++;
		}
		i++;
	}
	write_bmp("screenshot.bmp", &canvas); 
}

t_image     render_mlx_image(t_camera c, t_world w, void *mlx_ptr)
{
	t_image	im;
	int		i;
	int		j;
    
    i = 0;
    j = 0;
	im = mlx_create_img(mlx_ptr, w->r_width, w->r_height);
	while (i < im->height)
	{
		while (j < im->width)
		{
			img_set_pixel(im, j, i,
			create_color(color_at(w, ray_for_pixel(c, j, i))));
			j++;
		}
		i++;
	}
	return (im);
}