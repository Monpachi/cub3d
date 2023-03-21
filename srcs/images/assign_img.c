/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 10:33:08 by emtran            #+#    #+#             */
/*   Updated: 2023/03/21 19:54:28 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	assign_img_intro(t_data *data, t_game *game)
{
	game->intro->img = mlx_xpm_file_to_image(game->mlx_ptr, INTRO, \
	&game->intro->width, &game->intro->height);
	if (!game->intro->img)
		print_error_and_exit(ERR_MLC_IMG, data);
	game->credit->img = mlx_xpm_file_to_image(game->mlx_ptr, CREDIT, \
	&game->credit->width, &game->credit->height);
	if (!game->credit->img)
		print_error_and_exit(ERR_MLC_IMG, data);
	game->game_over->img = mlx_xpm_file_to_image(game->mlx_ptr, GAMEOVER, \
	&game->game_over->width, &game->game_over->height);
	if (!game->game_over->img)
		print_error_and_exit(ERR_MLC_IMG, data);
}
