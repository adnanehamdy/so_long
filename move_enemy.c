/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdy <ahamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 12:00:39 by ahamdy            #+#    #+#             */
/*   Updated: 2022/04/03 14:57:09 by ahamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	left(t_list *program, size_t x, size_t y)
{
	if (program->x == x && program->y == y - 1)
		program->counter = 1;
	program->map[x][y - 1] = '6';
	program->map[x][y] = '0';
	put_background(program, x, y, "background.xpm");
	put_enemy(program, x, y - 1, "enemy.xpm");
}

void	right(t_list *program, size_t x, size_t y)
{
	if (program->x == x && program->y + 1 == y)
		program->counter = 1;
	program->map[x][y + 1] = '6';
	program->map[x][y] = '0';
	put_background(program, x, y, "background.xpm");
	put_enemy(program, x, y + 1, "enemy.xpm");
}

void	up(t_list *program, size_t x, size_t y)
{
	if (program->x == x - 1 && program->y == y)
		program->counter = 1;
	program->map[x - 1][y] = '6';
	program->map[x][y] = '0';
	put_background(program, x, y, "background.xpm");
	put_enemy(program, x - 1, y, "enemy.xpm");
}

void	down(t_list *program, size_t x, size_t y)
{
	if (program->x == x + 1 && program->y == y)
		program->counter = 1;
	program->map[x + 1][y] = '6';
	program->map[x][y] = '0';
	put_background(program, x, y, "background.xpm");
	put_enemy(program, x + 1, y, "enemy.xpm");
}

int	detect_enemy_moves(t_list *program)
{
	size_t	x;
	size_t	y;
	int		fd;

	fd = open("/dev/random", O_RDONLY);
	if (fd == -1)
		exit(0);
	x = 0;
	while (program->map[x])
	{
		y = 0;
		while (program->map[x][y])
		{
			enemy_placement(program, x, y, fd);
			y++;
		}
		x++;
	}
	change_enemy_symbol(program);
	return (0);
}
