# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngda-sil <ngda-sil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/18 16:01:28 by ngda-sil          #+#    #+#              #
#    Updated: 2022/05/09 17:01:53 by ngda-sil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# ------------------------------------------------------------------------------

NAME		= fdf
CC			= gcc
CFLAGS 		= -g3 -Wall -Wextra -Werror
LFTDIR 		= ./Libft
LIBFT		= $(LFTDIR)/libft.a
MLX_DIR		= ./minilibx_macos
MINILIBX   	= -lmlx -framework OpenGL -framework AppKit -L minilibx_macos
SRC_PATH 	= ./src/
SRC 		= $(addprefix $(SRC_PATH), $(FILES))
OBJ			= $(SRC:.c=.o)
FILES 		= main.c \
			  hook.c \
			  menu.c \
			  image.c \
			  draw.c \
			  parser.c \
			  exit.c \
# ==============================================================================


all : $(OBJ)
	$(MAKE) -C $(LFTDIR)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MINILIBX) -o $(NAME)

clean :
	$(MAKE) -C $(LFTDIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -Rf $(OBJ)

fclean : clean
	$(MAKE) -C $(LFTDIR) fclean
	rm -Rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
