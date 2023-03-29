/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_write.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:50:29 by vchan             #+#    #+#             */
/*   Updated: 2023/03/29 15:50:32 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_putnbr(int nb, int fd)
{
	if (nb < 0)
	{
		ft_putchar('-', fd);
		nb *= -1;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10, fd);
	ft_putchar(nb % 10 + 48, fd);
}

void	ft_putstr(char *str, int fd)
{
	while (*str)
		ft_putchar(*(str++), fd);
}

void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}
