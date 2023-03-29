/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:44:17 by vchan             #+#    #+#             */
/*   Updated: 2023/03/29 16:20:44 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H
# define CHECK_H

# define CUB ".cub"

int		celling_floor_in_file(t_data *data, char **file, char *id, \
		int i);
int		check_path_arg_color(t_data *data, char *line_file, \
		char **split);
int		check_good_path_floor(t_data *data, t_color *color, char *line_file, \
		char *type);
int		check_all_floor_ceiling(t_data *data, t_floor *floor);
int		check_celling_floor(t_data *data, char **file);
int		check_file(char **argv, t_data *data);
int		is_cub(char *str);
int		check_alpha_in_map(t_data *data, char **map);
int		second_is_closed(t_data *data, char **map);
int		check_infos_in_first(char *line, int *count_info);
int		is_closed(t_data *data, char **map);
int		check_good_order_in_file(t_data *data, char **file);
int		first_and_last_line(t_data *data, char **map);
int		check_map(t_data *data, t_map *map);
int		check_line_is_empty(char *line);
int		check_kid_is_not_in_void(t_data *data, t_kid *kid, char **map);
int		check_position_of_kid(t_data *data, t_kid *kid, char **map);
int		zero_is_not_in_void(t_data *data, int y, int x, char **map);
int		check_one_delimiter_line_of_map(char *line);
int		ft_rgb_to_hex(int r, int g, int b);
int		is_it_an_id_in_file(t_data *data, char **file, char *id, int i);
int		check_good_path_wall(t_data *data, t_walls *walls, char *line_file, \
int		check_color(int n);
int		are_check_all_walls_is_ok(t_data *data, t_walls *walls);
int		check_walls(t_data *data, char **file);
		char *type);
bool	inverse_bool_wall(bool check);

#endif
