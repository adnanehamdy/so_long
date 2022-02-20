/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdy <ahamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:28:12 by ahamdy            #+#    #+#             */
/*   Updated: 2022/02/20 17:05:34 by ahamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	count_map_lines(char **c)
{
	size_t	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

void	check_map_lines_len(char **map)
{
	size_t	x;
	size_t	len;

	x = 0;
	len = ft_strlen(map[x++]);
	while (map[x])
	{
		if (len != ft_strlen(map[x]))
		{
			write(2, "error invalid map\n", 18);
			exit(1);
		}
		x++;
	}
}

void	error_exit(void)
{
	write(2, "error\n", 6);
	exit(1);
}

int	check_collec(t_list *program)
{
	int	i;
	int	y;

	y = 0;
	i = 0;
	while (program->map[i])
	{
		while (program->map[i][y])
		{
			if (program->map[i][y] == 'C')
				return (0);
		}
	}
	return (1);
}

int	exit_program(void)
{
	exit(0);
}
