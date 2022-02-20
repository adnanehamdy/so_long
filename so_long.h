/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdy <ahamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:52:08 by ahamdy            #+#    #+#             */
/*   Updated: 2022/02/20 17:01:07 by ahamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include<stdlib.h>
# include<fcntl.h>
# include<unistd.h>
# include "mlx.h"
# include "libft/libft.h"
# include<stdio.h>

typedef struct s_list
{
	void	*mlx_p;
	void	*window_p;
	void	*image_p;
	int		width;
	int		height;
	size_t	y;
	size_t	x;
	char	**map;
	int		count;
	int		end_game;
	int		counter;
}	t_list;

char	**convert_file_to_string(char *c);
size_t	count_map_lines(char **c);
void	check_len(char **map);
void	error_exit(void);
void	check_dup_newline(char *map_string);
void	put_images_to_window(t_list *program, char **map);
int		check_collec(t_list *program);
void	put_background(t_list *program, int x, int y, char *image);
int		detect_player_moves(int keycode, t_list *program);
int		exit_program(void);
int		check_collectible(t_list *program);
void	put_enemy(t_list *program, int x, int y, char *image);
int		switch_enemy_pic(t_list *program);
void	check_map_error(char **map, size_t y);
void	check_map_lines_len(char **map);
void	game_over(t_list *program);

/* functions that put the map conponent on the window*/
void	put_exit(t_list *program, int x, int y, char *image);
void	put_wall(t_list *program, size_t x, size_t y);
void	put_background(t_list *program, int x, int y, char *image);
void	put_player(t_list *program, int x, int y, char *image);
void	put_collect(t_list *program, int x, int y, char *image);

#endif