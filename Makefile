SRCS = ./bmp.c ./camera/camera.c ./camera/view_transform.c ./color.c ./CPCA/generic_arrays/array_heap/arr_heap_create.c ./CPCA/generic_arrays/array_heap/arr_heap_methods1.c ./CPCA/generic_arrays/array_heap/arr_heap_methods2.c ./CPCA/generic_arrays/array_heap/arr_heap_sort.c ./CPCA/generic_arrays/garray_create.c ./CPCA/generic_arrays/garray_tools1.c ./CPCA/generic_parrays/garrptr_create.c ./CPCA/generic_parrays/garrptr_tools1.c ./CPCA/generic_parrays/parray_heaps/parr_heap_create.c ./CPCA/generic_parrays/parray_heaps/parr_heap_methods1.c ./CPCA/generic_parrays/parray_heaps/parr_heap_methods2.c ./CPCA/generic_parrays/parray_heaps/parr_heap_sort.c ./CPCA/memory_tools.c ./libft/ft_atof.c ./libft/ft_atoi.c ./libft/ft_bzero.c ./libft/ft_calloc.c ./libft/ft_isalnum.c ./libft/ft_isalpha.c ./libft/ft_isascii.c ./libft/ft_isdigit.c ./libft/ft_isprint.c ./libft/ft_itoa.c ./libft/ft_mem_grow.c ./libft/ft_memccpy.c ./libft/ft_memchr.c ./libft/ft_memcmp.c ./libft/ft_memcpy.c ./libft/ft_memmove.c ./libft/ft_memset.c ./libft/ft_onealc.c ./libft/ft_putchar_fd.c ./libft/ft_putendl_fd.c ./libft/ft_putnbr_fd.c ./libft/ft_putstr_fd.c ./libft/ft_split.c ./libft/ft_strcat.c ./libft/ft_strchr.c ./libft/ft_strcmp.c ./libft/ft_strdup.c ./libft/ft_strjoin.c ./libft/ft_strlcat.c ./libft/ft_strlcpy.c ./libft/ft_strlen.c ./libft/ft_strmapi.c ./libft/ft_strncmp.c ./libft/ft_strnstr.c ./libft/ft_strrchr.c ./libft/ft_strstr.c ./libft/ft_strtrim.c ./libft/ft_substr.c ./libft/ft_tolower.c ./libft/ft_toupper.c ./libft/reverse_check.c ./lights/light.c ./main.c ./matrix/matrices_create.c ./matrix/matrices_tools1.c ./matrix/matrices_tools2.c ./matrix/matrices_tools3.c ./matrix/matrices_tools4.c ./matrix/matrix_transformations1.c ./matrix/matrix_transformations2.c ./mlx_image.c ./objects/cylinder.c ./objects/intersection.c ./objects/intersection_tools1.c ./objects/plane.c ./objects/sphere.c ./objects/square.c ./objects/triangle.c ./parser/data_checking/ambient_light.c ./parser/data_checking/check_arguments.c ./parser/data_checking/check_camera.c ./parser/data_checking/check_color.c ./parser/data_checking/check_floats.c ./parser/data_checking/check_l_cmps.c ./parser/data_checking/check_l_cmps2.c ./parser/data_checking/check_lights.c ./parser/data_checking/check_normal.c ./parser/data_checking/check_objs_syntax.c ./parser/data_checking/check_resolution.c ./parser/data_checking/parse_syntax.c ./parser/data_checking/syntax_buffer.c ./parser/data_getting/add_ambient.c ./parser/data_getting/get_camera.c ./parser/data_getting/get_data.c ./parser/data_getting/get_light.c ./parser/data_getting/get_objects.c ./parser/data_getting/get_resolution.c ./parser/file.c ./parser/rstring.c ./ray.c ./render.c ./shading/shading.c ./tools.c ./tuples/tuples_create.c ./tuples/tuples_tools_1.c ./tuples/tuples_tools_2.c ./world/world.c 
HEADER	= 
NAME	= miniRT
CC	 = gcc
FLAGS	 = -g
LFLAGS	 = -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit -lm

all:	$(NAME)

$(NAME):
	@echo "compiling miniRT"
	@gcc $(FLAGS) $(SRCS) -o $(NAME) $(LFLAGS)

clean:
	rm -f $(NAME)

