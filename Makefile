# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tel-dana <tel-dana@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 16:29:05 by tel-dana          #+#    #+#              #
#    Updated: 2023/01/23 14:46:14 by tel-dana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -f

LIBFT = inc/libft/libft.a
LIBFT_PATH = inc/libft/

SRCS = src/so_long.c src/parsing.c src/set_map.c src/hooks.c src/init_img.c \
		 src/moves.c src/events.c src/init_img2.c src/errors.c src/flood_fill.c
			 
OBJS = $(SRCS:.c=.o)

all: 	$(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_PATH)
	$(CC) $(CFLAGS)  -o $@ $^ $(LIBFT) -L. -lmlx -framework OpenGL -framework AppKit 
	@echo "$(GREEN)$(NAME) created!$(DEFAULT)"

clean:
	@$(RM) $(OBJS)
	@make -C $(LIBFT_PATH)  clean
	

fclean:	clean
	@$(RM) $(NAME) $(LIBFT) 

re:		fclean all
