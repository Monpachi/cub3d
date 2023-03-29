/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recognize_elements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:48:42 by vchan             #+#    #+#             */
/*   Updated: 2023/03/29 15:48:46 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	is_player(char c)
{
	if (c == 'N')
		return (0);
	else if (c == 'S')
		return (0);
	else if (c == 'E')
		return (0);
	else if (c == 'W')
		return (0);
	return (-1);
}

int	is_a_space_or_is_wall(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (0);
	else if (c == '1')
		return (0);
	return (-1);
}
