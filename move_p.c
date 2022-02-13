/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdy <ahamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:01:37 by ahamdy            #+#    #+#             */
/*   Updated: 2022/02/13 18:06:57 by ahamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void check_up(t_list *program)
{
	if (program->map[program->x - 1][program->y] == '1')
		return ;
	else if (program->map[program->x - 1][program->y] == 'E')
			check_collectible(program);
	else if ((program->map[program->x - 1][program->y] == 'C') ||
			(program->map[program->x - 1][program->y] == '0'))
			{
				put_background(program, program->x, program->y, "background.xpm");
				put_background(program, program->x  - 1, program->y, "background.xpm");
				program->map[program->x][program->y] = '0';
				program->map[program->x - 1][program->y] = '0';
				put_player(program, program->x - 1, program->y, "pup.xpm");
			}	
}

void check_left(t_list *program)
{
	if (program->map[program->x][program->y - 1] == '1')
		return ;
	else if (program->map[program->x][program->y - 1] == 'E')
			check_collectible(program);
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

void check_down(t_list *program)
{
	if (program->map[program->x  + 1][program->y] == '1')
		return ;
	else if (program->map[program->x + 1][program->y] == 'E')
			check_collectible(program);
	else if ((program->map[program->x + 1][program->y] == 'C') ||
			(program->map[program->x + 1][program->y] == '0'))
			{
				put_background(program, program->x, program->y, "background.xpm");
				put_background(program, program->x  + 1, program->y, "background.xpm");
				program->map[program->x][program->y] = '0';
				program->map[program->x + 1][program->y] = '0';
				put_player(program, program->x + 1, program->y, "pdown.xpm");
			}
}

void check_right(t_list *program)
{
	if (program->map[program->x][program->y + 1] == '1')
		return ;
	else if (program->map[program->x][program->y + 1] == 'E')
		{
			check_collectible(program);
		}
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

int move_player(int keycode, t_list *program)
{
	if (keycode == 13)
		check_up(program);
	else if (keycode == 0)
		check_left(program);
	else if (keycode == 1)
		check_down(program);
	else if (keycode == 2)
		check_right(program);
	else if (keycode == 53)
			exit(0);
	return (0);
}