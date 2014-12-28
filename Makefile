#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-bonn <ade-bonn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/28 13:08:46 by ade-bonn          #+#    #+#              #
#    Updated: 2014/12/28 14:16:08 by ade-bonn         ###   ########.fr        #
#                                                                              #
#******************************************************************************#


NAME = fdf

SOURCES = fdf.c \
			ft_memalloc.c  \
			ft_bzero.c \
			ft_strlen.c  \
			ft_strnew.c  \
			ft_atoi.c \
			ft_putendl_fd.c  \
			ft_strsplit.c \
			ft_putchar_fd.c  \
			ft_putstr_fd.c  \
			ft_strsub.c  \
			ft_draw.c \
			get_next_line.c \
			ft_drawline.c \
			ft_keypress.c \
			ft_strchr.c  \
			ft_strdel.c  \
			ft_strdup.c  \
			ft_strdup.c 	\
		 	ft_strjoin.c	\
			ft_memcpy.c

OBJECTS = $(SOURCES:.c=.o)

FLAGS = -Wall -Werror -Wextra -O3 -I ./includes -I /usr/X11/include

MLXFLAGS = -L/usr/X11/lib -lmlx -lX11 -lXext

all: $(NAME)

$(NAME): $(OBJECTS)
	
	$(CC) $(FLAGS) $(MLXFLAGS) -o $@ $^ 

%.o: %.c
	$(CC) $(FLAGS) -c $<

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re