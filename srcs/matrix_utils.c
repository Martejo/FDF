/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartel <gemartel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:43:46 by gemartel          #+#    #+#             */
/*   Updated: 2024/01/11 15:52:52 by gemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	words_counter(char const *str, char c)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i])
			words++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (words);
}

void	get_color(t_fdf **matrix, char **values, int y, int x)
{
	char	**color;
	int		i;

	if (ft_strnstr(values[x], ",0x", ft_strlen(values[x])) != NULL)
	{
		color = ft_split(values[x], ',');
		if (!color)
		{
			free2d(values);
			error_handler(MALLOC_E, matrix, 0);
		}
		i = 0;
		while (color[1][i++])
			color[1][i] = ft_tolower(color[1][i]);
		i = 0;
		while (color[1][i] != 'x')
			i++;
		matrix[y][x].color = ft_atoi_base(&color[1][++i],
				"0123456789abcdef", 16);
		free2d(color);
	}
	else if (matrix[y][x].z > 0)
		matrix[y][x].color = 0x48a23f;
	else
		matrix[y][x].color = 0xffffff;
}
