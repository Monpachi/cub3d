/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   introduction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:51:55 by vchan             #+#    #+#             */
/*   Updated: 2023/03/29 14:51:58 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	introduction_of_game(t_data *data, t_game *game)
{
	game->step_of_game = 1;
	mlx_key_hook(data->game->win_ptr, &key_press, data);
	mlx_hook(game->win_ptr, 33, 131072, &free_all_and_exit, data);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
	game->intro->img, 0, 0);
	mlx_loop(game->mlx_ptr);
}

void	credit_of_game(t_data *data, t_game *game)
{
	game->step_of_game = 2;
	mlx_key_hook(data->game->win_ptr, &key_press, data);
	mlx_hook(game->win_ptr, 33, 131072, &free_all_and_exit, data);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
	game->credit->img, 0, 0);
	mlx_loop(game->mlx_ptr);
}
