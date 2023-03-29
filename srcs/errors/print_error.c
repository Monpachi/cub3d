/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:51:12 by vchan             #+#    #+#             */
/*   Updated: 2023/03/29 15:42:00 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	print_error(char *error)
{
	ft_putstr(error, 2);
	return (-1);
}

int	print_error_and_exit(char *error, t_data *data)
{
	ft_putstr(error, 2);
	free_all(data);
	exit(EXIT_FAILURE);
	return (-1);
}

int	print_error_pars_and_exit(char *error, t_data *data)
{
	ft_putstr(error, 2);
	free_parsing_failed(data);
	exit(EXIT_FAILURE);
	return (-1);
}

void	check_error_arg(int argc)
{
	if (argc < 2)
		print_error(ERR_L_ARG);
	else
		print_error(ERR_H_ARG);
	exit(EXIT_FAILURE);
}
