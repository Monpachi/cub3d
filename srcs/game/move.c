/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 20:12:07 by dyoula            #+#    #+#             */
/*   Updated: 2023/03/21 19:44:02 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	w_key(t_data *data)
{
	double	x1;
	double	y1;
	double	x2;
	double	y2;

	if (data->game->p1->pos_x && data->game->p1->pos_y \
	&& data->game->step_of_game >= 3)
		draw_player(data, data->game->p1->pos_x, data->game->p1->pos_y, BLACK);
	x1 = (data->game->p1->pos_x + data->game->p1->dir_x \
	* data->game->p1->move_speed);
	y2 = (data->game->p1->pos_y + data->game->p1->dir_y \
	* data->game->p1->move_speed);
	x2 = (data->game->p1->pos_x);
	y1 = (data->game->p1->pos_y);
	if (data->map->map[(int)y1][(int)(x1)] != '1')
		data->game->p1->pos_x = x1;
	if (data->map->map[(int)y2][(int)x2] != '1')
		data->game->p1->pos_y = y2;
}

void	s_key(t_data *data)
{
	double	x1;
	double	y1;
	double	x2;
	double	y2;

	if (data->game->p1->pos_x && data->game->p1->pos_y \
	&& data->game->step_of_game >= 3)
		draw_player(data, data->game->p1->pos_x, data->game->p1->pos_y, BLACK);
	x1 = (data->game->p1->pos_x - data->game->p1->dir_x \
	* data->game->p1->move_speed);
	y2 = (data->game->p1->pos_y - data->game->p1->dir_y \
	* data->game->p1->move_speed);
	x2 = (data->game->p1->pos_x);
	y1 = (data->game->p1->pos_y);
	if (data->map->map[(int)y1][(int)(x1)] != '1')
		data->game->p1->pos_x = x1;
	if (data->map->map[(int)y2][(int)x2] != '1')
		data->game->p1->pos_y = y2;
}

void	a_key(t_data *data)
{
	double	x1;
	double	y1;
	double	x2;
	double	y2;

	if (data->game->p1->pos_x && data->game->p1->pos_y \
	&& data->game->step_of_game >= 3)
		draw_player(data, data->game->p1->pos_x, data->game->p1->pos_y, BLACK);
	x1 = (data->game->p1->pos_x + data->game->p1->dir_y \
	* data->game->p1->move_speed);
	y2 = (data->game->p1->pos_y - data->game->p1->dir_x \
	* data->game->p1->move_speed);
	x2 = (data->game->p1->pos_x);
	y1 = (data->game->p1->pos_y);
	if (data->map->map[(int)y1][(int)(x1)] != '1')
		data->game->p1->pos_x = x1;
	if (data->map->map[(int)y2][(int)x2] != '1')
		data->game->p1->pos_y = y2;

}

void	d_key(t_data *data)
{
	double	x1;
	double	y1;
	double	x2;
	double	y2;

	if (data->game->p1->pos_x && data->game->p1->pos_y \
	&& data->game->step_of_game >= 3)
		draw_player(data, data->game->p1->pos_x, data->game->p1->pos_y, BLACK);
	x1 = (data->game->p1->pos_x - data->game->p1->dir_y \
	* data->game->p1->move_speed);
	y2 = (data->game->p1->pos_y + data->game->p1->dir_x \
	* data->game->p1->move_speed);
	x2 = (data->game->p1->pos_x);
	y1 = (data->game->p1->pos_y);
	if (data->map->map[(int)y1][(int)(x1)] != '1')
		data->game->p1->pos_x = x1;
	if (data->map->map[(int)y2][(int)x2] != '1')
		data->game->p1->pos_y = y2;

}
