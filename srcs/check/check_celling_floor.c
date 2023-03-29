/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_celling_floor.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:50:28 by vchan             #+#    #+#             */
/*   Updated: 2023/03/29 16:17:22 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	celling_floor_in_file(t_data *data, char **file, char *id, int i)
{
	if (!ft_strncmp(file[i], id, 1))
	{
		if (!is_space(file[i][1]))
			print_error_pars_and_exit(ERR_ID_FC, data);
		return (0);
	}
	return (-1);
}

int	check_path_arg_color(t_data *data, char *line_file, char **split)
{
	int	len;

	len = ft_strlen(line_file);
	if (line_file[len - 1] == ',')
	{
		free_d_tab(split);
		print_error_pars_and_exit(ERR_NB_ARG_COLOR, data);
	}
	return (0);
}

int	check_good_path_floor(t_data *data, t_color *color, char *line_file, \
char *type)
{
	char	**split;

	split = NULL;
	split = ft_split_charset(line_file, SPACES);
	check_path_arg_color(data, line_file, split);
	if (!split[1] || split[2])
	{
		free_d_tab(split);
		print_error_pars_and_exit(ERR_NB_ARG_COLOR, data);
	}
	if (!ft_strcmp(type, "C"))
		color->path = ft_strdup(split[1]);
	else if (!ft_strcmp(type, "F"))
		color->path = ft_strdup(split[1]);
	free_d_tab(split);
	collect_rgb(data, color);
	return (0);
}

int	check_all_floor_ceiling(t_data *data, t_floor *floor)
{
	if (!floor->check_floor || !floor->check_celling)
		return (print_error_pars_and_exit(ERR_ID_FC_MISS, data));
	return (0);
}

int	check_celling_floor(t_data *data, char **file)
{
	int	i;

	i = 0;
	while (i < data->lines_file)
	{
		if (!celling_floor_in_file(data, file, "C", i))
			data->map->floor->check_floor = true;
		else if (!celling_floor_in_file(data, file, "F", i))
			data->map->floor->check_celling = true;
		i++;
	}
	check_all_floor_ceiling(data, data->map->floor);
	collect_celling_floor(data, file);
	return (0);
}
