/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_split_charset.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:49:43 by vchan             #+#    #+#             */
/*   Updated: 2023/03/29 15:49:45 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	is_charset(char c, char *charset)
{
	int	i;

	i = -1;
	while (charset[++i])
		if (c == charset[i])
			return (1);
	return (0);
}

int	size_word(char *s, char *c)
{
	int		count;

	count = 0;
	if (*s && is_charset(*s, c))
	{
		while (*s && is_charset(*s, c))
		{
			count++;
			s++;
		}
	}
	else if (*s && !is_charset(*s, c))
	{
		while (*s && !is_charset(*s, c))
		{
			count++;
			s++;
		}
	}
	return (count);
}

int	count_words(char *s, char *c)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (is_charset(s[i], c) && s[i])
		{
			while (is_charset(s[i], c) && s[i])
				i++;
		}
		else if (!is_charset(s[i], c) && s[i])
		{
			count++;
			while (!is_charset(s[i], c) && s[i])
				i++;
		}
	}
	return (count);
}

int	zap_charset(char *s, char *c)
{
	int		count;

	count = 0;
	if (*s && is_charset(*s, c))
	{
		while (*s && is_charset(*s, c))
		{
			count++;
			s++;
		}
	}
	return (count);
}

char	**ft_split_charset(char *s, char *c)
{
	char	**split;
	char	*flag;
	int		nb_words;
	int		index;

	if (!s)
		return (NULL);
	flag = NULL;
	flag = s;
	nb_words = count_words(s, c);
	split = (char **)malloc(sizeof(char *) * (nb_words + 1));
	if (!split)
		return (NULL);
	split[nb_words] = NULL;
	index = -1;
	while (++index < nb_words)
	{
		split[index] = malloc(sizeof(char) * (size_word(flag, c) + 1));
		if (!split[index])
			return (free_split(split, index));
		ft_strlcpy(split[index], flag, (size_word(flag, c) + 1));
		flag += (size_word(flag, c));
		flag += (zap_charset(flag, c));
	}
	return (split);
}
