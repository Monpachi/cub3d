/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:44:32 by vchan             #+#    #+#             */
/*   Updated: 2023/03/29 15:44:34 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define ERR_CHAR "Error\n Wrong letter\n"
# define ERR_L_ARG "Error\nsomething missing...\n"
# define ERR_FILE "Error\nBad file!\n"
# define ERR_CUB "Error\nNot a Cub ! \n"
# define ERR_ID "Error\nDirection walls\n"
# define ERR_MAP_CLOSE "Error\n"
# define ERR_ID_MISS "Error\nDirection wall is missing\n"
# define ERR_H_ARG "Error\ntoo many arguments!\n"
# define ERR_DIR "Error\nError Directory\n"
# define ERR_KID_MUCH "Error\nIt is impossible to have more than two kids\n"
# define ERR_ID_FC_MISS "Error\nfloor celling is missing\n"
# define ERR_MAP "Error\nNo map!\n"
# define ERR_ID_FC "Error\nFloor celling in map is wrong\n"
# define ERR_MAP_FIRST_LINE "Error\n"
# define ERR_MAP_LINE "Error\n"
# define ERR_NB_NB_COLOR "Error\nToo much color\n"
# define ERR_COLOR "Error\nWrong colors\n"
# define ERR_MAP_LAST_LINE "Error\n"
# define ERR_MAP_TOO_STRONG "Error\n"
# define ERR_NB_ARG_WALLS "Error\n"
# define NO_ENV "Error\nMlx\n"
# define ERR_NO_KID "Error\nThe kid is missing\n"
# define ERR_NB_ARG_COLOR "Error\n COLOR!\n"
# define ERR_MALLOC "Error\nMalloc\n"
# define ERR_READ "Error\n"
# define ERR_MLC_IMG "Error\nNo good path\n"

int			print_error(char *error);
int			print_error_and_exit(char *error, t_data *data);
int			print_error_pars_and_exit(char *error, t_data *data);
void		check_error_arg(int argc);

#endif
