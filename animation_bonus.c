/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdy <ahamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:27:24 by ahamdy            #+#    #+#             */
/*   Updated: 2022/04/03 14:58:21 by ahamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	change_enemy_symbol(t_list *program)
{
	int	x;
	int	y;

	x = 0;
	while (program->map[x])
	{
		y = 0;
		while (program->map[x][y])
		{
			if (program->map[x][y] == '6')
				program->map[x][y] = '7';
			y++;
		}
		x++;
	}
}

void	enemy_placement(t_list *program, size_t x, size_t y, size_t fd)
{
	char	c;

	if (read(fd, &c, 1) == -1)
		exit(0);
	if (program->map[x][y] == '7')
	{
		if (program->map[x + 1][y] == '0' && program->counter == 0
			&& (c >= -128 && c <= -64))
			down(program, x, y);
		else if (program->map[x][y - 1] == '0' && program->counter == 0
			&& (c >= -63 && c <= 0))
			left(program, x, y);
		else if (program->map[x][y + 1] == '0' && program->counter == 0
			&& (c >= 1 && c <= 64))
			right(program, x, y);
		else if (program->map[x - 1][y] == '0' && program->counter == 0
			&& (c >= 65 && c <= 127))
			up(program, x, y);
	}
}

void	change_pic(t_list *program, char *enemy)
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
			{
				put_background(program, i, y, "background.xpm");
				put_collect(program, i, y, enemy);
			}
			y++;
		}
		i++;
	}
}

int	switch_coin_pic(t_list *program)
{
	static int	count = 0;
	static int	pic;

	check_collectible(program);
	game_over(program);
	if (count > 5000)
	{
		if (pic == 1)
			pic = 0;
		else
			pic = 1;
		if (pic == 1)
			change_pic(program, "coin.xpm");
		else
			change_pic(program, "coin2.xpm");
		count = 0;
		detect_enemy_moves(program);
	}
	count++;
	return (0);
}
