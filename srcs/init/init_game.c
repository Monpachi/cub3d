/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:52:20 by vchan             #+#    #+#             */
/*   Updated: 2023/03/29 15:41:56 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	init_mlx_and_window(t_data *data, t_game *game, t_win *window)
{
	(void) data;
	window->win_height = WINDOW_HEIGHT;
	window->win_width = WINDOW_WIDTH;
	game->win_ptr = mlx_new_window(game->mlx_ptr, window->win_width, \
	window->win_height, "Welcome to my playground !!!");
	if (game->win_ptr == NULL)
		return (-1);
	return (0);
}

void	init_pics(t_data *data, t_game *game)
{
	game->intro = malloc(sizeof(t_pic));
	init_pic(game->intro);
	if (!game->intro)
		print_error_and_exit(ERR_MALLOC, data);
	game->credit = malloc(sizeof(t_pic));
	init_pic(game->credit);
	if (!game->credit)
		print_error_and_exit(ERR_MALLOC, data);
	game->game_over = malloc(sizeof(t_pic));
	init_pic(game->game_over);
	if (!game->game_over)
		print_error_and_exit(ERR_MALLOC, data);
}

void	init_struct_game(t_data *data, t_game *game)
{
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
	game->step_of_game = 0;
	game->screen = NULL;
	game->screen = malloc(sizeof(t_img));
	if (!game->screen)
		print_error_and_exit(ERR_MALLOC, data);
	init_img(game->screen);
	if (!game->screen)
		print_error_and_exit(ERR_MALLOC, data);
	init_pics(data, game);
	init_texture(data, game->texture);
	init_struct_kid(game->kid);
}
