/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdy <ahamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 11:25:32 by ahamdy            #+#    #+#             */
/*   Updated: 2022/04/03 14:59:35 by ahamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_characters(char **map, int i, int j, int bonus)
{
	if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'E' &&
			map[i][j] != 'C' && map[i][j] != 'P')
	{
		if (bonus)
		{
			if (map[i][j] != '7')
				error_exit("error invalid map\n", 1);
		}
		else
			error_exit("error invalid map\n", 1);
	}
}

void	print_count(t_list *program, int count)
{
	char	*num;

	num = ft_itoa(count);
	put_wall(program, 0, 0);
	mlx_string_put(program->mlx_p, program->window_p, 0 * 32, 0 * 32,
		0, num);
	ft_putstr_fd(num, 1);
	ft_putstr_fd("\n", 1);
	free(num);
}
