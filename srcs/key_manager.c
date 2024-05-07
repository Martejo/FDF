/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartel <gemartel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:35:37 by gemartel          #+#    #+#             */
/*   Updated: 2024/01/15 08:42:35 by gemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	on_destroy(t_fdf **matrix)
{
	mlx_destroy_window(DATA.mlx_ptr, DATA.win_ptr);
	mlx_destroy_display(DATA.mlx_ptr);
	free(DATA.mlx_ptr);
	free_matrix(matrix, 0);
	exit (EXIT_SUCCESS);
	return (0);
}

int	is_key(int key)
{
	return (key == UP || key == DOWN || key == LEFT || key == RIGHT
		|| key == SPACE || key == MINUS || key == PLUS || key == STAR
		|| key == DIV || key == UP_Z || key == DOWN_Z);
}

void	do_key(int key, t_fdf **matrix)
{
	if (key == PLUS)
		DATA.scale += 3;
	if (key == MINUS)
		DATA.scale -= 3;
	if (key == UP_Z)
		DATA.z_scale += 1;
	if (key == DOWN_Z)
		DATA.z_scale -= 1;
	if (key == UP)
		DATA.shift_y -= 10;
	if (key == DOWN)
		DATA.shift_y += 10;
	if (key == LEFT)
		DATA.shift_x -= 10;
	if (key == RIGHT)
		DATA.shift_x += 10;
	if (key == STAR)
		DATA.angle += 0.05;
	if (key == DIV)
		DATA.angle -= 0.05;
}

int	key_handler(int key, t_fdf **matrix)
{
	ft_printf("key = %d\n", key);
	if (is_key(key))
	{
		mlx_clear_window(DATA.mlx_ptr, DATA.win_ptr);
		do_key(key, matrix);
		if (key == SPACE)
		{
			if (DATA.is_isometric == 1)
				DATA.is_isometric = 0;
			else
				DATA.is_isometric = 1;
		}
		print_menu(DATA);
		draw_handler(matrix);
	}
	if (key == ONE || key == TWO || key == THREE || key == FOUR || key == FIVE)
		new_window(key, matrix);
	if (key == ESC)
		on_destroy(matrix);
	return (0);
}
