/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdy <ahamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:51:10 by ahamdy            #+#    #+#             */
/*   Updated: 2022/02/20 16:48:02 by ahamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_list	*program;
	int		window_x_size;
	int		window_y_size;

	if (ac != 2)
		exit(1);
	program = (t_list *)malloc(sizeof(t_list));
	program->mlx_p = mlx_init();
	program->map = convert_file_to_string(av[1]);
	program->count = 0;
	program->end_game = 0;
	window_x_size = ft_strlen(program->map[0]) * 32;
	window_y_size = count_map_lines(program->map) * 32;
	program->window_p = mlx_new_window(program->mlx_p,
			window_x_size, window_y_size, "game");
	put_images_to_window(program, program->map);
	mlx_hook(program->window_p, 2, 0, detect_player_moves, program);
	mlx_hook(program->window_p, 17, 0, exit_program, NULL);
	mlx_loop_hook(program->mlx_p, switch_enemy_pic, program);
	mlx_loop(program->mlx_p);
}
