/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdy <ahamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:51:19 by ahamdy            #+#    #+#             */
/*   Updated: 2022/02/13 17:59:21 by ahamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void sub_check(int *exit, int *start, int *collectible, char **map)
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
			if (map[i][j] == 'E')
				exit[0]++;
			else if (map[i][j] == 'P')
				start[0]++;
			else if (map[i][j] == 'C')
				collectible[0]++;
			j++;
		}
		i++;
	}
}

void check_player(char **map)
{
	int exit_point;
	int start;
	int	collectible;

	start = 0;
	collectible = 0;
	exit_point = 0;
	sub_check(&exit_point, &start, &collectible, map);
	if (exit_point >= 1 && start == 1 && collectible >= 1)
		return ;
	write(2,"error invalid map\n",18);
	exit(1);
}

void check_error(char **map, size_t y)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (i == 0 || j == 0  || j == (ft_strlen(map[i]) - 1) || i == y - 1)
			{
				if (map[i][j] != '1')
				{
					write(2, "error invalid map\n",18);
					exit(1);
				}
			}
			j++;
		}
		i++;
	}
	check_player(map);
	check_len(map);
	wrong_char(map);
}

char **read_file(int fd)
{
	ssize_t		eof;
	char	*line;
	char	*tmp;
	char	*buffer;

	buffer = (char *)malloc(1001);
	line = ft_strdup("");
	eof = 1;
	while (eof)
	{
		eof = read(fd, buffer, 1000);
		buffer[eof] = 0;
		tmp = line;
		line = ft_strjoin(line, buffer);
		free(tmp);
		if (!line)
			error_exit();
	}
	free(buffer);
	check_dup(line);
	return (ft_split(line, '\n'));
}

char  **map_function(char *c)
{
	int		fd;
	char	**map;
	int		i;

	i = 0;
	if (!ft_strncmp(&c[ft_strlen(c) - 4], ".ber",4))
	{
		fd = open(c, O_RDONLY);
		if (fd == -1)
			error_exit();
	}
	else
	{
		write(2,"wrong file extention\n",20);
		exit(1);
	}
	map = read_file(fd);
	if(!map)
		exit(1);
	int j;
	j = 0;
	i = ft_strlen_p(map);
	check_error(map, i);
	return (map);
}
