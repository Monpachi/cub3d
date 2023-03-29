/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:51:31 by vchan             #+#    #+#             */
/*   Updated: 2023/03/29 15:24:27 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	free_sprites(t_sprites *sprites)
{
	if (sprites->tex)
		free(sprites->tex);
	if (sprites)
		free(sprites);
}

void	free_maps(t_map *map)
{
	if (map->walls->path_no)
		free(map->walls->path_no);
	if (map->walls->path_so)
		free(map->walls->path_so);
	if (map->walls->path_we)
		free(map->walls->path_we);
	if (map->walls->path_ea)
		free(map->walls->path_ea);
	if (map->walls)
		free(map->walls);
	if (map->floor)
		free(map->floor);
	if (map->map)
		free_d_tab(map->map);
	if (map)
		free(map);
}

void	free_pics(t_game *game, t_pic *pic)
{
	if (pic->img)
		mlx_destroy_image(game->mlx_ptr, pic->img);
	if (pic)
		free(pic);
}

void	free_game_and_mlx(t_game *game)
{
	if (game->step_of_game >= 3)
		free_img(game, game->screen);
	else
		free(game->screen);
	free_pics(game, game->intro);
	free_pics(game, game->credit);
	free_pics(game, game->game_over);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	if (game->kid)
		free(game->kid);
	if (game->p1)
		free(game->p1);
}
