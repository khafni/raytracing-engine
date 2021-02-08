#include "view_transform.h"

t_camera	camera(int hsize, int vsize, float fov, t_matrice tr)
{
	t_camera	c;
	float		aspect_ratio;

	c = malloc(sizeof(struct s_camera));
	c->vsize = vsize;
	c->hsize = hsize;
	c->fov = fov;
	c->transform = tr;
	c->tran_inv = inverse(c->transform);
	c->origin = matrix_4x4_multiply_by_tuple(c->transform,
	point(0, 0, 0));
	calc_pixel_size(c);
	return (c);
}

void		camera_destroy(void *c_)
{
	t_camera c;

	c = (t_camera)c_;
	matrix_destroy(c->transform);
	matrix_destroy(c->tran_inv);
	free(c);
}