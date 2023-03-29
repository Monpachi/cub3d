/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_kid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:27:21 by vchan             #+#    #+#             */
/*   Updated: 2023/03/29 16:19:11 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	check_kid_is_not_in_void(t_data *data, t_kid *kid, char **map)
{
	if (!is_void(map[kid->y_kid][kid->x_kid - 1]))
		print_error_pars_and_exit(ERR_MAP_CLOSE, data);
	else if (!is_void(map[kid->y_kid - 1][kid->x_kid]))
		print_error_pars_and_exit(ERR_MAP_CLOSE, data);
	else if (!is_void(map[kid->y_kid][kid->x_kid + 1]))
		print_error_pars_and_exit(ERR_MAP_CLOSE, data);
	else if (!is_void(map[kid->y_kid + 1][kid->x_kid]))
		print_error_pars_and_exit(ERR_MAP_CLOSE, data);
	return (0);
}

int	zero_is_not_in_void(t_data *data, int y, int x, char **map)
{
	if (!is_good_value_and_walls(map[y][x - 1]))
		print_error_pars_and_exit(ERR_MAP_CLOSE, data);
	else if (!is_good_value_and_walls(map[y - 1][x]))
		print_error_pars_and_exit(ERR_MAP_CLOSE, data);
	else if (!is_good_value_and_walls(map[y][x + 1]))
		print_error_pars_and_exit(ERR_MAP_CLOSE, data);
	else if (!is_good_value_and_walls(map[y + 1][x]))
		print_error_pars_and_exit(ERR_MAP_CLOSE, data);
	return (0);
}

int	check_position_of_kid(t_data *data, t_kid *kid, char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[++y])
	{
		x = 0;
		while (map[y][++x])
		{
			if (is_position(map[y][x]))
			{
				kid->check_kid++;
				if (kid->check_kid > 1)
					print_error_pars_and_exit(ERR_KID_MUCH, data);
				kid->pos_kid = map[y][x];
				kid->x_kid = x;
				kid->y_kid = y;
				check_kid_is_not_in_void(data, kid, map);
			}
		}
	}
	if (!kid->check_kid)
		print_error_pars_and_exit(ERR_NO_KID, data);
	return (0);
}
