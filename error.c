/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdy <ahamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:40:13 by ahamdy            #+#    #+#             */
/*   Updated: 2022/02/13 17:59:48 by ahamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	wrong_char(char **map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'E' &&
			map[i][j] != 'C' && map[i][j] != '7' && map[i][j] != 'P')
			{
				write(2, "error invalid map\n",18);
				exit(1);
			}
			j++;
		}
		i++;
	}
}