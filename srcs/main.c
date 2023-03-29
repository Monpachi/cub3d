/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:54:00 by vchan             #+#    #+#             */
/*   Updated: 2023/03/29 15:39:48 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	game_impression(t_data *data)
{
	mlx_put_image_to_window(data->game->mlx_ptr, data->game->win_ptr, \
		data->game->screen->mlx_img, 0, 0);
	mlx_put_image_to_window(data->game->mlx_ptr, data->game->win_ptr, \
		data->img->mlx_img, 729, 819);
	return (0);
}

int	game_running(t_data *data)
{
	int	x;
	int	line_height;
	int	draw_start;
	int	draw_end;

	x = 0;
	while (x < WINDOW_WIDTH)
	{
		reset_values(data->game->p1, x);
		step_manager(data->game->p1);
		while (data->game->p1->hit == 0)
			jump_next_map_square(data, data->game->p1);
		check_side(data->game->p1);
		line_height = (int)(WINDOW_GAME / data->game->p1->perp_wall_dist);
		draw_start = -line_height / 2 + WINDOW_GAME / 2;
		draw_end = line_height / 2 + WINDOW_GAME / 2;
		if (draw_end >= WINDOW_GAME)
			draw_end = WINDOW_GAME - 1;
		verline(data, x, draw_start, draw_end);
		x++;
	}
	return (game_impression(data));
}

int	game_start(t_data *data)
{
	data->game->step_of_game = 3;
	data->game->screen->mlx_img = \
	mlx_new_image(data->game->mlx_ptr, WINDOW_WIDTH, WINDOW_GAME);
	data->game->screen->addr = \
	mlx_get_data_addr(data->game->screen->mlx_img, &data->game->screen->bpp, \
	&data->game->screen->line_len, &data->game->screen->endian);
	init_val(data->game->p1);
	data->game->p1->pos_x = data->game->kid->x_kid + 0.5;
	data->game->p1->pos_y = data->game->kid->y_kid + 0.5;
	set_view_of_kid(data, data->game->p1);
	data->img->mlx_img = mlx_new_image(data->game->mlx_ptr, 450, 163);
	data->img->addr = mlx_get_data_addr(data->img->mlx_img, &data->img->bpp, \
	&data->img->line_len, &data->img->endian);
	size_map(data, &data->map->size_x, &data->map->size_y);
	create_img_of_walls(data, data->map->walls, data->game->texture);
	mlx_loop_hook(data->game->mlx_ptr, &game_running, data);
	mlx_hook(data->game->win_ptr, 0, KeyPressMask, &key_press, data);
	mlx_hook(data->game->win_ptr, 33, 131072, &free_all_and_exit, data);
	mlx_loop(data->game->mlx_ptr);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = NULL;
	if (argc == 2)
	{
		data = init_struct(data);
		data->game->mlx_ptr = mlx_init();
		if (!data->game->mlx_ptr)
			print_error_and_exit(NO_ENV, data);
		if (check_parsing(argv, data))
		{
			free_parsing_failed(data);
			return (1);
		}
		assign_img_intro(data, data->game);
		init_mlx_and_window(data, data->game, &data->win);
		introduction_of_game(data, data->game);
		game_start(data);
		free_all(data);
	}
	else
		check_error_arg(argc);
	return (0);
}
