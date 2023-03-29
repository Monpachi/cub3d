/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:52:37 by vchan             #+#    #+#             */
/*   Updated: 2023/03/29 15:18:39 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	init_pic(t_pic *pic)
{
	pic->img = NULL;
	pic->width = 0;
	pic->height = 0;
}

void	init_struct_kid(t_kid *kid)
{
	kid->check_kid = 0;
	kid->x_kid = 0;
	kid->y_kid = 0;
}

void	init_color(t_color *color)
{
	color->path = NULL;
	color->hexa = 0;
	color->r = 0;
	color->g = 0;
	color->b = 0;
}

void	cub_init_sprites(t_data *data, t_sprites *sprites)
{
	int		j;

	sprites->tex = (int *)malloc(sizeof(int) * (SPRITE_W * SPRITE_H));
	if (!sprites->tex)
		print_error_and_exit(ERR_MALLOC, data);
	j = 0;
	while (j < SPRITE_W * SPRITE_H)
	{
		sprites->tex[j] = 0;
		j++;
	}
}

void	init_sprites(t_data *data, t_sprites *sprites)
{
	sprites->path = NULL;
	sprites->x = 0;
	sprites->y = 0;
	sprites->texture = 0;
	sprites->sprite_distance = 0;
	sprites->spritex = 0;
	sprites->spritey = 0;
	sprites->invdet = 0;
	sprites->transformx = 0;
	sprites->transformy = 0;
	sprites->spritescreenx = 0;
	sprites->sprite_height = 0;
	sprites->sprite_width = 0;
	sprites->draw_start_y = 0;
	sprites->draw_start_x = 0;
	sprites->draw_end_y = 0;
	sprites->draw_end_x = 0;
	sprites->stripe = 0;
	sprites->tex_x = 0;
	sprites->tex_y = 0;
	cub_init_sprites(data, sprites);
}
