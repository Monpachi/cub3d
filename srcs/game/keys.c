/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:39:21 by emtran            #+#    #+#             */
/*   Updated: 2023/03/21 20:00:58 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	move_player(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	draw_player(data, data->game->p1->pos_x, data->game->p1->pos_y, RED);
	draw_map(data, x, y);
	return (0);
}

int	key_release_main(int keysym, void *data)
{
	(void)data;
	(void)keysym;
	return (0);
}

int	key_press_two(int key, t_data *data)
{
	if (key == KEY_RIGHT && data->game->step_of_game >= 3)
		right_key(data);
	else if (key == KEY_LEFT && data->game->step_of_game >= 3)
		left_key(data);
	else if (key == ESP && data->game->step_of_game == 1)
		credit_of_game(data, data->game);
	else if (key == ESP && data->game->step_of_game == 2)
		game_start(data);
	else if (key == ESC)
		free_all_and_exit(data);
	else if (data->game->step_of_game >= 3)
		move_player(data);
	return (0);
}

int	key_press(int key, t_data *data)
{
	if (key == KEY_W && data->game->step_of_game >= 3)
		w_key(data);
	else if (key == KEY_S && data->game->step_of_game >= 3)
		s_key(data);
	else if (key == KEY_A && data->game->step_of_game >= 3)
		a_key(data);
	else if (key == KEY_D && data->game->step_of_game >= 3)
		d_key(data);
	return (key_press_two(key, data));
}
