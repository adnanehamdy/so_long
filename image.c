/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdy <ahamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 10:59:15 by ahamdy            #+#    #+#             */
/*   Updated: 2022/02/20 16:47:29 by ahamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	collectible_check(t_list *program)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (program->map[i])
	{
		y = 0;
		while (program->map[i][y])
		{
			if (program->map[i][y] == 'C')
				return (1);
			y++;
		}
		i++;
	}
	return (0);
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

void	put_wall(t_list *program, size_t x, size_t y)
{
	if (x == 0 || y == 0 || y == (ft_strlen(program->map[0]) - 1)
		|| x == (count_map_lines(program->map) - 1))
	{
		program->image_p = mlx_xpm_file_to_image(program->mlx_p,
				"wall.xpm", &program->width, &program->height);
		mlx_put_image_to_window(program->mlx_p, program->window_p,
			program->image_p, 32 * y, 32 * x);
	}
	else
	{
		program->image_p = mlx_xpm_file_to_image(program->mlx_p,
				"stone.xpm", &program->width, &program->height);
		mlx_put_image_to_window(program->mlx_p,
			program->window_p, program->image_p, 32 * y, 32 * x);
	}
}

void	put_images_to_window(t_list *program, char **map)
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
				put_collect(program, i, j, "collectible.xpm");
			else if (map[i][j] == 'E')
				put_exit(program, i, j, "door.xpm");
			else if (map[i][j] == '7')
				put_enemy(program, i, j, "enemy.xpm");
			j++;
		}
		i++;
	}
}

int	check_collectible(t_list *program)
{
	int	check;
	int	width;
	int	height;

	width = 0;
	height = 0;
	check = collectible_check(program);
	if (check == 1)
		return (1);
	if (program->end_game && program->count == 0)
	{
		program->image_p = mlx_xpm_file_to_image(program->mlx_p,
				"yeah.xpm", &width, &height);
		mlx_put_image_to_window(program->mlx_p, program->window_p,
			program->image_p, program->y * 32, (program->x - 1) * 32);
		program->count++;
	}
	else if (program->end_game)
			program->count++;
	if (program->count == 5000)
	{
		write(2, "you won\n", 8);
		exit(0);
	}
	return (0);
}
