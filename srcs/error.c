/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartel <gemartel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:35:21 by gemartel          #+#    #+#             */
/*   Updated: 2024/01/11 15:37:54 by gemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	free_matrix(t_fdf **matrix, int y)
{
	int	i;

	i = 0;
	while (i < y || matrix[i] != NULL)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	free2d(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
}

void	error_handler(int error, t_fdf **matrix, int y)
{
	if (matrix)
		free_matrix(matrix, y);
	if (error == MALLOC_E)
		ft_error("Error malloc.\n");
	if (error == READ_E)
		ft_error("Error\n Function read fail\n");
	if (error == DIMENSIONS_E)
		ft_error("Error\nInvalid map size.\n");
}

void	ft_error(char	*msg)
{
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}
