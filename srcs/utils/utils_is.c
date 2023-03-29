/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_is.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:49:23 by vchan             #+#    #+#             */
/*   Updated: 2023/03/29 15:49:26 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	is_good_value(char c)
{
	int			a;
	const char	*str = ACCEPTED_VALUES;

	a = -1;
	while (str[++a] != '\0')
	{
		if (str[a] == c)
			return (1);
	}
	return (0);
}

int	is_good_value_and_walls(char c)
{
	int			a;
	const char	*str = ACCEPTED_VALUES_AND_WALLS;

	a = -1;
	while (str[++a] != '\0')
	{
		if (str[a] == c)
			return (1);
	}
	return (0);
}

int	is_position(char c)
{
	int			a;
	const char	*str = POSITION;

	a = -1;
	while (str[++a] != '\0')
	{
		if (str[a] == c)
			return (1);
	}
	return (0);
}

int	is_space(char c)
{
	int			a;
	const char	*str = SPACES;

	a = -1;
	while (str[++a] != '\0')
	{
		if (str[a] == c)
			return (1);
	}
	return (0);
}

int	is_digit(char c)
{
	int			a;
	const char	*str = DIGITS;

	a = -1;
	while (str[++a] != '\0')
	{
		if (str[a] == c)
			return (1);
	}
	return (0);
}
