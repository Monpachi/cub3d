/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:45:04 by vchan             #+#    #+#             */
/*   Updated: 2023/03/29 15:45:06 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

int		render(t_data *data);
int		draw_map(t_data *data, int size_x, int size_y);
int		place_player(t_data *data, int size_x, int size_y);

/*						DRAW_LINES.C					*/
int		draw_bottom(t_data *data, int *x, int *y, int size_x);
int		draw_right_wall(t_data *data, int *x, int *y, int size_y);
void	distinct_walls(t_data *data, int *x, int y, int size_x);
void	draw_player(t_data *data, int x, int y, int color);

/*						VERIFICATIONS.C					*/
int		wall_touched(t_data *data, int size_x, int size_y, int key);
int		vector_has_touched(t_data *data, int size_x, int size_y, int dir);

#endif
