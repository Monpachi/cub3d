/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:52:07 by vchan             #+#    #+#             */
/*   Updated: 2023/03/29 15:42:58 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	player_first_location(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (0);
	return (-1);
}

void	find_player(t_data *data, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (data->map->map[i])
	{
		j = 0;
		while (data->map->map[i][j])
		{
			if (player_first_location(data->map->map[i][j]) == 0)
			{
				*x = j;
				*y = i;
			}
			j++;
		}
		i++;
	}
}
