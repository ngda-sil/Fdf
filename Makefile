# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngda-sil <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/18 16:01:28 by ngda-sil          #+#    #+#              #
#    Updated: 2022/04/22 10:15:28 by ngda-sil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# ------------------------------------------------------------------------------

NAME		= fdf
CC			= gcc
CFLAGS 		= -Wall -Wextra -Werror
LFTDIR 		= ./Libft
LIBFT		= $(LFTDIR)/libft.a
MINILIBX    = -lmlx -framework OpenGL -framework AppKit -L minilibx_macos
SRC_PATH 	= ./src/
SRC 		= $(addprefix $(SRC_PATH), $(FILES))
OBJ			= $(SRC:.c=.o)
FILES 		= main.c \
			  hook.c \
			  menu.c \
			  image.c \
			  draw.c \

# ==============================================================================


all : $(OBJ)
	$(MAKE) -C $(LFTDIR)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MINILIBX) -o $(NAME)

clean :
	$(MAKE) -C $(LFTDIR) clean
	rm -Rf $(OBJ)

fclean : clean
	$(MAKE) -C $(LFTDIR) fclean
	rm -Rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
