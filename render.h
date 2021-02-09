#ifndef RENDER_H
# define RENDER_H

# include "world/world.h"
# include "shading/shading.h"
# include "bmp.h"
# include "mlx_image.h"

t_tup		color_at(t_world w, t_ray r);

void		render_bmp(t_camera c, t_world w);

t_image     render_mlx_image(t_camera c, t_world w, void *mlx_ptr);
void        render_mlx_generate_imgs(t_world w);
void        render_mlx(t_world w);
void        render(int argc, char **argv, t_world w);
#endif