#ifndef RENDER_H
# define RENDER_H

# include "world/world.h"
# include "shading/shading.h"
# include "bmp.h"

t_tup		color_at(t_world w, t_ray r);

t_bmp		render(t_camera c, t_world w);

#endif