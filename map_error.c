/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdy <ahamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:24:20 by ahamdy            #+#    #+#             */
/*   Updated: 2022/03/24 11:19:40 by ahamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_invalid_conponents(char **map)
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
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'E' &&
			map[i][j] != 'C' && map[i][j] != 'P')
			{
				write(2, "error invalid map\n", 18);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	count_map_conponents(int *exit, int *start, int *collec, char **map)
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
			if (map[i][j] == 'E')
				exit[0]++;
			else if (map[i][j] == 'P')
				start[0]++;
			else if (map[i][j] == 'C')
				collec[0]++;
			j++;
		}
		i++;
	}
}

void	check_map_conponents(char **map)
{
	int	exit_point;
	int	start;
	int	collectible;

	start = 0;
	collectible = 0;
	exit_point = 0;
	count_map_conponents(&exit_point, &start, &collectible, map);
	if (exit_point >= 1 && start == 1 && collectible >= 1)
		return ;
	write(2, "error invalid map\n", 18);
	exit(1);
}

void	check_dup_newline(char *map_string)
{
	int	i;

	i = 0;
	while (map_string[i])
	{
		if ((map_string[0] == '\n')
			|| (map_string[i] == '\n' && map_string[i + 1] == '\n'))
		{
			write(2, "error invalid map\n", 18);
			exit(1);
		}
		i++;
	}
	if (map_string[i - 1] == '\n')
	{
		write(2, "error invalid map\n", 18);
		exit(1);
	}
}

void	check_map_error(char **map, size_t y)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (i == 0 || j == 0 || j == (ft_strlen(map[i]) - 1) || i == y - 1)
			{
				if (map[i][j] != '1')
				{
					write(2, "error invalid map\n", 18);
					exit(1);
				}
			}
			j++;
		}
		i++;
	}
	check_map_conponents(map);
	check_map_lines_len(map);
	check_invalid_conponents(map);
}
