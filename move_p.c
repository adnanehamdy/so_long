/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdy <ahamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:01:37 by ahamdy            #+#    #+#             */
/*   Updated: 2022/04/03 14:57:28 by ahamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	up_move(t_list *program)
{
	if (program->map[program->x - 1][program->y] == '1')
		return (0);
	else if (program->map[program->x - 1][program->y] == 'E' &&
				!check_collectible(program))
		program->end_game = 1;
	else if (program->map[program->x - 1][program->y] == '7')
			program->counter++;
	else if ((program->map[program->x - 1][program->y] == 'C') ||
			(program->map[program->x - 1][program->y] == '0'))
	{
		put_background(program, program->x, program->y, "background.xpm");
		put_background(program, program->x - 1, program->y, "background.xpm");
		program->map[program->x][program->y] = '0';
		program->map[program->x - 1][program->y] = '0';
		put_player(program, program->x - 1, program->y, "pup.xpm");
		return (1);
	}
	return (0);
}

int	left_move(t_list *program)
{
	if (program->map[program->x][program->y - 1] == '1')
		return (0);
	else if (program->map[program->x][program->y - 1] == 'E'
				&& !check_collectible(program))
		program->end_game = 1;
	else if (program->map[program->x][program->y - 1] == '7')
			program->counter++;
	else if ((program->map[program->x][program->y - 1] == 'C') ||
			(program->map[program->x][program->y - 1] == '0'))
	{
		put_background(program, program->x, program->y, "background.xpm");
		put_background(program, program->x, program->y - 1, "background.xpm");
		program->map[program->x][program->y] = '0';
		program->map[program->x][program->y - 1] = '0';
		put_player(program, program->x, program->y - 1, "pleft.xpm");
		return (1);
	}
	return (0);
}

int	down_move(t_list *program)
{
	if (program->map[program->x + 1][program->y] == '1')
		return (0);
	else if (program->map[program->x + 1][program->y] ==
				'E' && !check_collectible(program))
		program->end_game = 1;
	else if (program->map[program->x + 1][program->y] == '7')
			program->counter++;
	else if ((program->map[program->x + 1][program->y] == 'C') ||
			(program->map[program->x + 1][program->y] == '0'))
	{
		put_background(program, program->x, program->y, "background.xpm");
		put_background(program, program->x + 1, program->y, "background.xpm");
		program->map[program->x][program->y] = '0';
		program->map[program->x + 1][program->y] = '0';
		put_player(program, program->x + 1, program->y, "pdown.xpm");
		return (1);
	}
	return (0);
}

int	right_move(t_list *program)
{
	if (program->map[program->x][program->y + 1] == '1')
		return (0);
	else if (program->map[program->x][program->y + 1] ==
			'E' && !check_collectible(program))
			program->end_game = 1;
	else if (program->map[program->x][program->y + 1] == '7')
			program->counter++;
	else if ((program->map[program->x][program->y + 1] == 'C') ||
			(program->map[program->x][program->y + 1] == '0'))
	{
		put_background(program, program->x, program->y, "background.xpm");
		put_background(program, program->x, program->y + 1, "background.xpm");
		program->map[program->x][program->y] = '0';
		program->map[program->x][program->y + 1] = '0';
		put_player(program, program->x, program->y + 1, "pright.xpm");
		return (1);
	}
	return (0);
}

int	detect_player_moves(int keycode, t_list *program)
{
	static int	count;
	int			is_move;

	is_move = 0;
	if (program->end_game)
		return (0);
	if (keycode == 13 && program->counter == 0)
		is_move = up_move(program);
	else if (keycode == 0 && program->counter == 0)
		is_move = left_move(program);
	else if (keycode == 1 && program->counter == 0)
		is_move = down_move(program);
	else if (keycode == 2 && program->counter == 0)
		is_move = right_move(program);
	else if (keycode == 53)
		exit(0);
	if (is_move)
	{
		count++;
		print_count(program, count);
	}
	return (0);
}
