/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdy <ahamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:52:08 by ahamdy            #+#    #+#             */
/*   Updated: 2022/04/03 14:51:28 by ahamdy           ###   ########.fr       */
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

char	**convert_file_to_string(char *c, int bonus);
size_t	count_map_lines(char **c);
void	check_len(char **map);
void	error_exit(char *str, int num);
void	check_dup_newline(char *map_string);
void	put_images_to_window(t_list *program, char **map);
int		check_collec(t_list *program);
void	put_background(t_list *program, int x, int y, char *image);
int		detect_player_moves(int keycode, t_list *program);
int		exit_program(void);
int		check_collectible(t_list *program);
void	put_enemy(t_list *program, int x, int y, char *image);
int		switch_coin_pic(t_list *program);
void	check_map_error(char **map, size_t y, int bonus);
void	check_map_lines_len(char **map);
void	game_over(t_list *program);
void	check_characters(char **map, int i, int j, int bonus);
int		detect_enemy_moves(t_list *program);

/* functions that put the map conponent on the window*/
void	put_exit(t_list *program, int x, int y, char *image);
void	put_wall(t_list *program, size_t x, size_t y);
void	put_background(t_list *program, int x, int y, char *image);
void	put_player(t_list *program, int x, int y, char *image);
void	put_collect(t_list *program, int x, int y, char *image);
void	print_count(t_list *program, int count);
void	put_collect(t_list *program, int x, int y, char *image);
void	put_images_to_windows(t_list *program, char **map);
void	enemy_placement(t_list *program, size_t x, size_t y, size_t fd);
void	down(t_list *program, size_t x, size_t y);
void	up(t_list *program, size_t x, size_t y);
void	right(t_list *program, size_t x, size_t y);
void	left(t_list *program, size_t x, size_t y);
void	change_enemy_symbol(t_list *program);
#endif