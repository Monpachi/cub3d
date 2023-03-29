/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:52:40 by vchan             #+#    #+#             */
/*   Updated: 2023/03/29 15:41:11 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	draw_bottom(t_data *data, int *x, int *y, int size_x)
{
	int	i;

	i = 0;
	while (i < size_x)
	{
		img_pix_put(data->img, \
		(*x + i), *y, WHITE);
		i++;
	}
	return (0);
}

int	draw_right_wall(t_data *data, int *x, int *y, int size_y)
{
	int	i;

	i = 0;
	while (i < size_y)
	{
		img_pix_put(data->img, \
		*x, *y + i, WHITE);
		i++;
	}
	return (0);
}

void	distinct_walls(t_data *data, int *x, int y, int size_x)
{
	int	i;

	i = 0;
	while (i < size_x)
	{
		img_pix_put(data->img, *x + i, y, WHITE);
		i++;
	}
}

void	draw_player(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;

	j = -1;
	x = data->game->p1->pos_x * data->map->size_x;
	y = data->game->p1->pos_y * data->map->size_y;
	while (j < 3)
	{
		i = 0;
		while (i < 3)
		{
			img_pix_put(data->img, x + i, y + j, color);
			i++;
		}
		j++;
	}
}
