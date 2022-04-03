/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdy <ahamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:02:25 by ahamdy            #+#    #+#             */
/*   Updated: 2022/03/24 11:32:22 by ahamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_background(t_list *program, int x, int y, char *image)
{
	program->image_p = mlx_xpm_file_to_image(program->mlx_p, image,
			&program->width, &program->height);
	mlx_put_image_to_window(program->mlx_p, program->window_p,
		program->image_p, 32 * y, 32 * x);
	mlx_destroy_image(program->mlx_p, program->image_p);
}

void	put_player(t_list *program, int x, int y, char *image)
{
	program->image_p = mlx_xpm_file_to_image(program->mlx_p, image,
			&program->width, &program->height);
	mlx_put_image_to_window(program->mlx_p, program->window_p,
		program->image_p, 32 * y, 32 * x);
	mlx_destroy_image(program->mlx_p, program->image_p);
	program->x = x;
	program->y = y;
}

void	put_collect(t_list *program, int x, int y, char *image)
{
	program->image_p = mlx_xpm_file_to_image(program->mlx_p, image,
			&program->width, &program->height);
	mlx_put_image_to_window(program->mlx_p, program->window_p,
		program->image_p, 32 * y, 32 * x);
	mlx_destroy_image(program->mlx_p, program->image_p);
}

void	put_exit(t_list *program, int x, int y, char *image)
{
	program->image_p = mlx_xpm_file_to_image(program->mlx_p,
			image, &program->width, &program->height);
	mlx_put_image_to_window(program->mlx_p, program->window_p,
		program->image_p, 32 * y, 32 * x);
	mlx_destroy_image(program->mlx_p, program->image_p);
}
