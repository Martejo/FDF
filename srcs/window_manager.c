/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartel <gemartel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:35:53 by gemartel          #+#    #+#             */
/*   Updated: 2024/01/11 15:46:50 by gemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	check_win_size(int key, t_fdf **matrix)
{
	if ((key == THREE && DATA.win_y <= 500)
		|| (key == ONE && DATA.win_x <= 500))
		return (1);
	if ((key == FOUR && DATA.win_y > 1000)
		|| (key == TWO && DATA.win_x > 2000))
		return (1);
	return (0);
}

void	full_screen(t_fdf **matrix)
{
	static int	old_x;
	static int	old_y;

	if (DATA.win_x != 2560)
	{
		old_x = DATA.win_x;
		old_y = DATA.win_y;
	}
	if (DATA.win_x == 2560)
		DATA.win_x = old_x;
	else
		DATA.win_x = 2560;
	if (DATA.win_y == 1400)
		DATA.win_y = old_y;
	else
		DATA.win_y = 1400;
}

void	change_window_size(int key, t_fdf **matrix)
{
	if (check_win_size(key, matrix))
		return ;
	if (key == ONE)
		DATA.win_x -= 100;
	if (key == TWO)
		DATA.win_x += 100;
	if (key == THREE)
		DATA.win_y -= 100;
	if (key == FOUR)
		DATA.win_y += 100;
	if (key == FIVE)
		full_screen(matrix);
}

void	new_window(int key, t_fdf **matrix)
{
	change_window_size(key, matrix);
	mlx_destroy_window(DATA.mlx_ptr, DATA.win_ptr);
	DATA.win_ptr = mlx_new_window(DATA.mlx_ptr, DATA.win_x, DATA.win_y, "FDF");
	DATA.shift_x = (DATA.win_x - DATA.width_map) / 2;
	DATA.shift_y = (DATA.win_y - DATA.height_map) / 2;
	draw_handler(matrix);
	mlx_key_hook(DATA.win_ptr, key_handler, matrix);
	mlx_loop(DATA.mlx_ptr);
}
