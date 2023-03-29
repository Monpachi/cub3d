/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_failed_parsing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:51:17 by vchan             #+#    #+#             */
/*   Updated: 2023/03/29 15:24:32 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	check_parsing(char **argv, t_data *data)
{
	if (check_extension_cub(argv[1]))
		return (print_error_pars_and_exit(ERR_CUB, data));
	if (check_file(argv, data))
		return (1);
	if (check_map(data, data->map))
		return (1);
	return (0);
}

void	free_forest(t_data *data)
{
	free_sprites(data->sprites);
	free_maps(data->map);
	free_texture(data->game, data->game->texture);
	free_pics(data->game, data->game->intro);
	free_pics(data->game, data->game->credit);
	free_pics(data->game, data->game->game_over);
}

int	free_parsing_failed(t_data *data)
{
	free_forest(data);
	if (data->game->kid)
		free(data->game->kid);
	if (data->game->p1)
		free(data->game->p1);
	if (data->game->screen)
		free(data->game->screen);
	mlx_destroy_display(data->game->mlx_ptr);
	free(data->game->mlx_ptr);
	if (data->game)
		free(data->game);
	if (data->file)
		free_d_tab(data->file);
	if (data->img)
		free(data->img);
	if (data)
		free(data);
	return (1);
}
