/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdy <ahamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:01:37 by ahamdy            #+#    #+#             */
/*   Updated: 2022/02/20 17:11:51 by ahamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up_move(t_list *program)
{
	if (program->map[program->x - 1][program->y] == '1')
		return ;
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
	}	
}

void	left_move(t_list *program)
{
	if (program->map[program->x][program->y - 1] == '1')
		return ;
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
	}
}

void	down_move(t_list *program)
{
	if (program->map[program->x + 1][program->y] == '1')
		return ;
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
	}
}

void	right_move(t_list *program)
{
	if (program->map[program->x][program->y + 1] == '1')
		return ;
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
	}
}

int	detect_player_moves(int keycode, t_list *program)
{
	static int	count;
	int			sleep;

	sleep = 0;
	if (program->end_game)
		return (0);
	if (keycode == 13)
		up_move(program);
	else if (keycode == 0)
		left_move(program);
	else if (keycode == 1)
		down_move(program);
	else if (keycode == 2)
		right_move(program);
	else if (keycode == 53)
		exit(0);
	put_wall(program, 0, 0);
	mlx_string_put(program->mlx_p, program->window_p, 0 * 32, 0 * 32,
		0, ft_itoa(count));
	count++;
	return (0);
}
