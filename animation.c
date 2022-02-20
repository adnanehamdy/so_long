/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdy <ahamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:16:43 by ahamdy            #+#    #+#             */
/*   Updated: 2022/02/19 13:24:45 by ahamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			if (program->map[i][y] == '7')
			{
				put_background(program, i, y, "background.xpm");
				put_enemy(program, i, y, enemy);
			}
			y++;
		}
		i++;
	}
}

int	switch_enemy_pic(t_list *program)
{
	static int	count;
	static int	pic;

	check_collectible(program);
	game_over(program);
	if (count > 2000)
	{
		if (pic == 1)
			pic = 0;
		else
			pic = 1;
		if (pic == 1)
			change_pic(program, "enemy.xpm");
		else
			change_pic(program, "enemy001.xpm");
		count = 0;
	}
	else
		count++;
	return (0);
}
