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

void		render_bmp(t_world w)
{
	t_bmp		canvas;
	int			i;
	int			j;
	t_camera	c;
    
	c = arrptr_get(w->cameras, 0);
    i = 0;
    j = 0;
 	canvas = create_pixels_array(c->vsize, c->hsize);
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
	int		i_inc;
    
	i_inc = 0;
    j = 0;
	im = mlx_create_img(mlx_ptr, w->r_width, w->r_height);
	i = im->height - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < im->width)
		{
			img_set_pixel(im, j, i_inc,
			create_color(color_at(w, ray_for_pixel(c, j, i))));
			j++;
		}
		i_inc++;
		i--;
	}
	return (im);
}

void        render_mlx_generate_imgs(t_world w)
{
	int			i;
	t_camera	c;


	w->mlx_ptr = mlx_init();
	w->mlx_window = mlx_new_window(w->mlx_ptr, w->r_width, w->r_height, "window");
	i = 0;
	while (i < w->cameras->len)
	{
		c = arrptr_get(w->cameras, i);
		arrptr_add(w->mlx_images, render_mlx_image(c, w, w->mlx_ptr));
		i++;
	}
}

void        render_mlx(t_world w)
{
	
}


/* void        render(int argc, char **argv, t_world w)
{
	if (argc == 3)
		render_bmp(w);
	else
	{
		
	}
}
 */