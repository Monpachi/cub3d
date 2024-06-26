/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:49:38 by vchan             #+#    #+#             */
/*   Updated: 2023/03/29 15:49:40 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	*ft_memset(void *s, int a, int c)
{
	int		b;
	char	*ch;

	ch = s;
	b = 0;
	while (b < c)
	{
		ch[b] = (unsigned char)a;
		b++;
	}
	return (s);
}

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	char			*chdest;
	char			*chsrc;
	unsigned int	i;

	chdest = (char *)dest;
	chsrc = (char *)src;
	if (dest == 0 && src == 0)
		return (0);
	i = 0;
	while (i < count)
	{
		chdest[i] = chsrc[i];
		i++;
	}
	return (dest);
}

void	*ft_memcpy_with_one_char(void *dest, const char c, size_t count)
{
	char			*chdest;
	char			chsrc;
	unsigned int	i;

	chdest = (char *)dest;
	chsrc = c;
	if (dest == 0 && c == 0)
		return (0);
	i = 0;
	while (i < count)
	{
		chdest[i] = chsrc;
		i++;
	}
	return (dest);
}

char	*ft_strcalloc(size_t size)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (0);
	i = 0;
	while (i < size + 1)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

void	*ft_calloc(size_t num, size_t size)
{
	char	*c;
	size_t	i;

	c = malloc(size * num);
	if (c == 0)
		return (0);
	i = 0;
	while (i < num * size)
	{
		c[i] = 0;
		i++;
	}
	return (c);
}
