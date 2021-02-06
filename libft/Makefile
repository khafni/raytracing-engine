# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khafni <khafni@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/30 02:19:49 by khafni            #+#    #+#              #
#    Updated: 2021/02/02 15:51:04 by khafni           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean all re fclean
NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
SRCS =  ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c \
ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strstr.c ft_strncmp.c ft_strcmp.c ft_atoi.c \
ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_calloc.c\
ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c\
ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_onealc.c reverse_check.c ft_atof.c ft_mem_grow.c
OBJS = $(SRCS:.c=.o)
all:$(NAME)
$(NAME):
	gcc $(CFLAGS) -c $(SRCS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
clean:
	rm -f $(OBJS)
	rm -f $(OBBS)
fclean: clean
	rm -f $(NAME)
re: fclean all
