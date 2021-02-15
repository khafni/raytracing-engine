SRCS = ./bmp.c ./camera/camera.c ./camera/view_transform.c ./color.c ./lights/light.c ./main.c ./matrix/matrices_create.c ./matrix/matrices_tools1.c ./matrix/matrices_tools2.c ./matrix/matrices_tools3.c ./matrix/matrices_tools4.c ./matrix/matrix_transformations1.c ./matrix/matrix_transformations2.c ./objects/cylinder.c ./objects/intersection.c ./objects/intersection_tools1.c ./objects/plane.c ./objects/sphere.c ./objects/square.c ./objects/triangle.c ./parser/data_checking/ambient_light.c ./parser/data_checking/check_arguments.c ./parser/data_checking/check_camera.c ./parser/data_checking/check_color.c ./parser/data_checking/check_floats.c ./parser/data_checking/check_l_cmps.c ./parser/data_checking/check_l_cmps2.c ./parser/data_checking/check_lights.c ./parser/data_checking/check_normal.c ./parser/data_checking/check_objs_syntax.c ./parser/data_checking/check_resolution.c ./parser/data_checking/parse_syntax.c ./parser/data_checking/syntax_buffer.c ./parser/data_getting/add_ambient.c ./parser/data_getting/get_camera.c ./parser/data_getting/get_data.c ./parser/data_getting/get_light.c ./parser/data_getting/get_objects.c ./parser/data_getting/get_resolution.c ./parser/file.c ./parser/rstring.c ./ray.c ./rendering/mlx_image.c ./rendering/render.c ./rendering/render_mlx.c ./rendering/render_mlx_keys_handeling.c ./shading/shading.c ./tools.c ./tuples/tuples_create.c ./tuples/tuples_tools_1.c ./tuples/tuples_tools_2.c ./world/world.c 
NAME	= miniRT
CC	 = gcc
CFLAGS	 = -Wall -Wextra -Werror
LFLAGS	 = -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit -lm

all:$(NAME)
$(NAME):
	@$(MAKE) -C CPCA
	@$(MAKE) -C helper_functions
	@echo "\033[0;32mcompiling miniRT"
	@gcc $(CFLAGS) CPCA/CPCA.a helper_functions/HELPER_FUNCTIONS.a $(SRCS) -o $(NAME) $(LFLAGS)

clean:
	@$(MAKE) -C CPCA clean
fclean:
	@rm -f $(NAME)
	@$(MAKE) -C CPCA fclean
	@$(MAKE) -C helper_functions fclean
	@echo "\033[0;33meverything cleaned"

re : fclean all