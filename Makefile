# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahamdy <ahamdy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/10 11:31:47 by ahamdy            #+#    #+#              #
#    Updated: 2022/03/24 11:15:05 by ahamdy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CFLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit

SRCS = main.c map_file.c tools.c image.c move_p.c map_error.c  put_images.c 


LIBFT = libft/libft.a

NAME = so_long

all : $(NAME)

$(NAME) : $(LIBFT) $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT)  -o $(NAME)

$(LIBFT):
	make -C libft/


clean :
	make clean -C libft/

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re