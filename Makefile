# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marmoral <marmoral@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/15 14:17:36 by marmoral          #+#    #+#              #
#    Updated: 2023/04/22 00:00:54 by marmoral         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -I ./includes/fractol.h

LPATH	= ./libft/
MLX		= ./mlx/

SRCS	= $(addprefix src/, fractol.c utils.c functions.c ft_atod.c actions.c)
OBJS	= $(SRCS:.c=.o)
MLXFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJS)
	$(MAKE) -C $(LPATH)
	$(MAKE) -C $(MLX)
	$(CC) $(OBJS) $(CFLAGS) $(LPATH)libft.a $(MLXFLAGS) -o $(NAME)

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C $(LPATH)
	$(MAKE) clean -C $(MLX)

fclean: clean
	rm -rf $(NAME)
	$(MAKE) fclean -C $(LPATH)

re: fclean all

.phony: all libft clean fclean mlx 