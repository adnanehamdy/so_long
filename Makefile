# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahamdy <ahamdy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/10 11:31:47 by ahamdy            #+#    #+#              #
#    Updated: 2022/04/02 12:47:18 by ahamdy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = gcc
AR = ar rc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c map_file.c tools.c image.c move_p.c map_error.c put_images.c extra_tools.c
OBJS = $(SRCS:.c=.o)
B_SRCS = main_bonus.c map_file.c tools.c image.c move_p.c map_error.c animation_bonus.c put_images.c extra_tools.c move_enemy.c
B_OBJS = $(B_SRCS:.c=.o)

NAME = mandatory.a
BONUS = bonus.a

LIBFT = libft/libft.a

all : $(NAME)

bonus : $(BONUS)

$(NAME) : $(LIBFT) $(OBJS)
	rm -rf $(BONUS)
	$(AR) $(NAME) $(OBJS)
	$(CC) $(CFLAGS) $(NAME) libft/libft.a -lmlx -framework OpenGL -framework AppKit -o so_long

$(BONUS) : $(LIBFT) $(B_OBJS)
	rm -rf $(NAME)
	$(AR) $(BONUS) $(B_OBJS)
	$(CC) $(CFLAGS) $(BONUS) libft/libft.a -lmlx -framework OpenGL -framework AppKit -o so_long

$(LIBFT):
	make -C libft/

clean :
	rm -rf $(OBJS) $(B_OBJS)
	make clean -C libft/

fclean : clean
	rm -f $(NAME) $(BONUS) so_long 
	rm -rf libft/libft.a

re : fclean all

.PHONY : all clean fclean bonus re