/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdy <ahamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:51:19 by ahamdy            #+#    #+#             */
/*   Updated: 2022/03/22 13:14:22 by ahamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_file(int fd)
{
	ssize_t	eof;
	char	*map_string;
	char	*tmp;
	char	*buffer;
	char	**map;

	buffer = (char *)malloc(1001);
	map_string = ft_strdup("");
	eof = 1;
	while (eof)
	{
		eof = read(fd, buffer, 1000);
		buffer[eof] = 0;
		tmp = map_string;
		map_string = ft_strjoin(map_string, buffer);
		free(tmp);
		if (!map_string)
			error_exit("error\n", 1);
	}
	free(buffer);
	check_dup_newline(map_string);
	map = ft_split(map_string, '\n');
	free(map_string);
	return (map);
}

char	open_file(char *filename)
{
	int	fd;

	fd = 0;
	if (!ft_strncmp(&filename[ft_strlen(filename) - 4], ".ber", 4))
	{
		fd = open(filename, O_RDONLY);
		if (fd == -1)
			error_exit("can't create file descriptor\n", 1);
	}
	else
	{
		write(2, "wrong file extention\n", 20);
		exit(1);
	}
	return (fd);
}

char	**convert_file_to_string(char *filename)
{
	int		fd;
	char	**map;
	int		map_lines;
	int		j;

	map_lines = 0;
	j = 0;
	fd = open_file(filename);
	map = read_file(fd);
	if (!map)
		exit(1);
	map_lines = count_map_lines(map);
	check_map_error(map, map_lines);
	return (map);
}
