/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_view.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:53:51 by vchan             #+#    #+#             */
/*   Updated: 2023/03/29 15:40:44 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	set_view_of_kid_suite(t_data *data, t_player *p1)
{
	if (data->game->kid->pos_kid == 'W')
	{
		p1->dir_x = -1;
		p1->dir_y = 0;
		p1->plane_x = 0;
		p1->plane_y = -0.66;
	}
	else if (data->game->kid->pos_kid == 'E')
	{
		p1->dir_x = 1;
		p1->dir_y = 0;
		p1->plane_x = 0;
		p1->plane_y = -0.66;
	}
	return (0);
}

int	set_view_of_kid(t_data *data, t_player *p1)
{
	if (data->game->kid->pos_kid == 'N')
	{
		p1->dir_x = 0;
		p1->dir_y = -1;
		p1->plane_x = -0.66;
		p1->plane_y = 0;
	}
	else if (data->game->kid->pos_kid == 'S')
	{
		p1->dir_x = 0;
		p1->dir_y = 1;
		p1->plane_x = -0.66;
		p1->plane_y = 0;
	}
	return (set_view_of_kid_suite(data, p1));
}
