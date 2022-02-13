/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdy <ahamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:51:10 by ahamdy            #+#    #+#             */
/*   Updated: 2022/02/13 17:38:23 by ahamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
	t_list *program;

	program = (t_list *)malloc(sizeof(t_list));
	program->mlx_p = mlx_init();
	if (ac != 2)
		exit(1);
	program->map = map_function(av[1]);
	program->window_p = mlx_new_window(program->mlx_p, ft_strlen(program->map[0]) * 32, ft_strlen_p(program->map) * 32, "game");
	draw_image(program, program->map);
	mlx_hook(program->window_p, 2, 0, move_player, program);
	mlx_hook(program->window_p, 17, 0, exit_program, NULL);
	mlx_loop(program->mlx_p);

}