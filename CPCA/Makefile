.PHONY: clean all re fclean
SRCS = ./generic_arrays/array_heap/arr_heap_create.c ./generic_arrays/array_heap/arr_heap_methods1.c ./generic_arrays/array_heap/arr_heap_methods2.c ./generic_arrays/array_heap/arr_heap_sort.c ./generic_arrays/garray_create.c ./generic_arrays/garray_tools1.c ./generic_parrays/garrptr_create.c ./generic_parrays/garrptr_tools1.c ./generic_parrays/parray_heaps/parr_heap_create.c ./generic_parrays/parray_heaps/parr_heap_methods1.c ./generic_parrays/parray_heaps/parr_heap_methods2.c ./generic_parrays/parray_heaps/parr_heap_sort.c ./memory_tools.c
SOURCES = arr_heap_create.c  arr_heap_methods1.c  arr_heap_methods2.c  arr_heap_sort.c  garray_create.c  garray_tools1.c  garrptr_create.c  garrptr_tools1.c  parr_heap_create.c  parr_heap_methods1.c  parr_heap_methods2.c  parr_heap_sort.c  memory_tools.c
OBJS = $(SOURCES:.c=.o)
CFLAGS = -Wall -Wextra -Werror
NAME	= CPCA.a
CC	 = gcc
all:$(NAME)
$(NAME):
	@echo "\033[1;32mcompiling CPCA static library"
	@gcc $(CFLAGS) -c $(SRCS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
clean:
	@echo "\033[0;33mclean CPCA obj files"
	@rm -f $(OBJS)
	@rm -f $(OBBS)
fclean: clean
	@echo "clean everything related to CPCA library"
	@rm -f $(NAME)
re: fclean all