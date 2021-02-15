.PHONY: clean all re fclean
SRCS = ./ft_atof.c ./ft_atoi.c ./ft_bzero.c ./ft_calloc.c ./ft_isalnum.c ./ft_isalpha.c ./ft_isascii.c ./ft_isdigit.c ./ft_isprint.c ./ft_itoa.c ./ft_mem_grow.c ./ft_memccpy.c ./ft_memchr.c ./ft_memcmp.c ./ft_memcpy.c ./ft_memmove.c ./ft_memset.c ./ft_onealc.c ./ft_putchar_fd.c ./ft_putendl_fd.c ./ft_putnbr_fd.c ./ft_putstr_fd.c ./ft_split.c ./ft_strcat.c ./ft_strchr.c ./ft_strcmp.c ./ft_strdup.c ./ft_strjoin.c ./ft_strlcat.c ./ft_strlcpy.c ./ft_strlen.c ./ft_strmapi.c ./ft_strncmp.c ./ft_strnstr.c ./ft_strrchr.c ./ft_strstr.c ./ft_strtrim.c ./ft_substr.c ./ft_tolower.c ./ft_toupper.c ./reverse_check.c
SOURCES = ft_atof.c  ft_atoi.c  ft_bzero.c  ft_calloc.c  ft_isalnum.c  ft_isalpha.c  ft_isascii.c  ft_isdigit.c  ft_isprint.c  ft_itoa.c  ft_mem_grow.c  ft_memccpy.c  ft_memchr.c  ft_memcmp.c  ft_memcpy.c  ft_memmove.c  ft_memset.c  ft_onealc.c  ft_putchar_fd.c  ft_putendl_fd.c  ft_putnbr_fd.c  ft_putstr_fd.c  ft_split.c  ft_strcat.c  ft_strchr.c  ft_strcmp.c  ft_strdup.c  ft_strjoin.c  ft_strlcat.c  ft_strlcpy.c  ft_strlen.c  ft_strmapi.c  ft_strncmp.c  ft_strnstr.c  ft_strrchr.c  ft_strstr.c  ft_strtrim.c  ft_substr.c  ft_tolower.c  ft_toupper.c  reverse_check.c
OBJS = $(SOURCES:.c=.o)
CFLAGS = -Wall -Wextra -Werror
NAME	= HELPER_FUNCTIONS.a
CC	 = gcc
all:$(NAME)
$(NAME):
	@echo "\033[1;32mcompiling helper_functions static library"
	@gcc $(CFLAGS) -c $(SRCS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
clean:
	@echo "cleaning helper functions objs files"
	@rm -f $(OBJS)
	@rm -f $(OBBS)
fclean: clean
	@echo "\033[0;33mcleaning everything helper functions related"
	@rm -f $(NAME)
re: fclean all
	@echo "\033[0;33mremaking goes brrrrrr"