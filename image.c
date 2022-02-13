/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdy <ahamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 10:59:15 by ahamdy            #+#    #+#             */
/*   Updated: 2022/02/13 18:14:55 by ahamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void put_rock(t_list *program, int x, int y)
{
	program->image_p = mlx_xpm_file_to_image(program->mlx_p, "rock.xpm", &program->width, &program->height);
	mlx_put_image_to_window(program->mlx_p, program->window_p, program->image_p, 32 * y, 32 * x);
}

void put_background(t_list *program, int x, int y, char *image)
{
	program->image_p = mlx_xpm_file_to_image(program->mlx_p, image, &program->width, &program->height);
	mlx_put_image_to_window(program->mlx_p, program->window_p, program->image_p, 32 * y, 32 * x);
}

void put_player(t_list *program, int x, int y, char *image)
{
	program->image_p = mlx_xpm_file_to_image(program->mlx_p, image, &program->width, &program->height);
	mlx_put_image_to_window(program->mlx_p, program->window_p, program->image_p, 32 * y, 32 * x);
	program->x = x;
	program->y = y;
}

void put_collect(t_list *program, int x, int y, char *image)
{
	program->image_p = mlx_xpm_file_to_image(program->mlx_p, image, &program->width, &program->height);
	mlx_put_image_to_window(program->mlx_p, program->window_p, program->image_p, 32 * y, 32 * x);
}

void put_exit(t_list *program, int x, int y, char *image)
{
	program->image_p = mlx_xpm_file_to_image(program->mlx_p, image, &program->width, &program->height);
	mlx_put_image_to_window(program->mlx_p, program->window_p, program->image_p, 32 * y, 32 * x);
}

void put_enemy(t_list *program, int x, int y, char *image)
{
	program->image_p = mlx_xpm_file_to_image(program->mlx_p, image, &program->width, &program->height);
	mlx_put_image_to_window(program->mlx_p, program->window_p, program->image_p, 32 * y, 32 * x);
}

void draw_image(t_list *program, char **map)
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
				put_rock(program, i, j);
			else if (map[i][j] == 'P')
				put_player(program, i, j, "pup.xpm");
			else if (map[i][j] == 'C')
				put_collect(program, i, j, "chest.xpm");
			else if (map[i][j] == 'E')
			 	put_exit(program, i, j, "ship.xpm");
			else if (map[i][j] == '7')
				put_enemy(program, i, j, "enemy.xpm");
			j++;
		}
		i++;
	}
}

void check_collectible(t_list *program)
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
				return ;
			y++;
		}
		i++;
	}
	exit(0);
}