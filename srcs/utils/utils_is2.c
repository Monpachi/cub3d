/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_is2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:49:30 by vchan             #+#    #+#             */
/*   Updated: 2023/03/29 16:18:29 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	has_str_only_spaces(char *str)
{
	int	a;

	a = 0;
	while (str[a] != '\0')
	{
		if (is_space(str[a]))
			a++;
		else
			return (0);
	}
	return (1);
}

int	has_str_only_walls(char *str)
{
	int	a;

	a = 0;
	while (str[a] != '\0')
	{
		if (str[a] == '1' || is_space(str[a]))
			a++;
		else
			return (0);
	}
	return (1);
}

int	is_void(char c)
{
	int			a;
	const char	*str = BIN;

	a = -1;
	while (str[++a] != '\0')
	{
		if (str[a] == c)
			return (1);
	}
	return (0);
}
