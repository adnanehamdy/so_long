/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdy <ahamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:25:52 by ahamdy            #+#    #+#             */
/*   Updated: 2022/04/03 14:56:31 by ahamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_images_to_windows(t_list *program, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			put_background(program, i, j, "background.xpm");
			if (map[i][j] == '1')
				put_wall(program, i, j);
			else if (map[i][j] == 'P')
				put_player(program, i, j, "pup.xpm");
			else if (map[i][j] == 'C')
				put_collect(program, i, j, "coin.xpm");
			else if (map[i][j] == 'E')
				put_exit(program, i, j, "door.xpm");
			else if (map[i][j] == '7')
				put_enemy(program, i, j, "enemy.xpm");
			j++;
		}
		i++;
	}
}

void	put_enemy(t_list *program, int x, int y, char *image)
{
	program->image_p = mlx_xpm_file_to_image(program->mlx_p, image,
			&program->width, &program->height);
	mlx_put_image_to_window(program->mlx_p, program->window_p,
		program->image_p, 32 * y, 32 * x);
	mlx_destroy_image(program->mlx_p, program->image_p);
}

void	game_over(t_list *program)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	if (program->counter == 1)
	{
		program->image_p = mlx_xpm_file_to_image(program->mlx_p,
				"argl.xpm", &width, &height);
		mlx_put_image_to_window(program->mlx_p, program->window_p,
			program->image_p, program->y * 32, (program->x - 1) * 32);
		mlx_destroy_image(program->mlx_p, program->image_p);
		program->counter++;
	}
	if (program->counter >= 1)
		program->counter++;
	if (program->counter == 5000)
	{
		write(2, "game over\n", 10);
		exit(0);
	}
}

int	main(int ac, char **av)
{
	t_list	*program;
	int		window_x_size;
	int		window_y_size;

	if (ac != 2)
		error_exit("check the number of arguments\n", 1);
	program = (t_list *)malloc(sizeof(t_list));
	program->mlx_p = mlx_init();
	program->map = convert_file_to_string(av[1], 1);
	program->count = 0;
	program->end_game = 0;
	window_x_size = ft_strlen(program->map[0]) * 32;
	window_y_size = count_map_lines(program->map) * 32;
	program->window_p = mlx_new_window(program->mlx_p,
			window_x_size, window_y_size, "game");
	put_images_to_windows(program, program->map);
	mlx_hook(program->window_p, 2, 0, detect_player_moves, program);
	mlx_hook(program->window_p, 17, 0, exit_program, NULL);
	mlx_loop_hook(program->mlx_p, switch_coin_pic, program);
	mlx_loop(program->mlx_p);
}
