/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-bouh <kid-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 10:11:24 by kid-bouh          #+#    #+#             */
/*   Updated: 2021/11/11 21:53:33 by kid-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_sep(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] && s[i] == c)
				i++;
			count++;
		}
		if (s[i])
			i++;
	}
	if (s[i - 1] == c)
		return (count);
	return (count + 1);
}

static int	count_wrd(char const *str, char c, int index)
{
	int	i;

	i = 0;
	while (str[index] == c)
		index++;
	while (str[index] && str[index] != c)
	{
		i++;
		index++;
	}
	return (i);
}

static char	**ft_free(char **dest, int j)
{
	int	i;

	i = 0;
	if (j == 0)
	{
		free(dest);
		return (NULL);
	}
	while (i < j)
	{
		free(dest[i]);
		i++;
	}
	return (NULL);
}

static char	**insert(char **dst, char const *s, char c)
{
	int	i;
	int	j;
	int	t;

	i = 0;
	j = 0;
	while (j < count_sep(s, c))
	{
		dst[j] = malloc((count_wrd(s, c, i) + 1) * sizeof(char));
		if (!dst[j])
			return (ft_free(dst, j));
		t = 0;
		while (s[i] == c)
			i++;
		while (s[i] && s[i] != c)
			dst[j][t++] = s[i++];
		dst[j][t] = '\0';
		j++;
	}
	dst[j] = NULL;
	return (dst);
}

char	**ft_split(char const *s, char c)
{
	char	**dst;

	if (!s)
		return (0);
	if (!*s)
	{
		dst = malloc(1 * sizeof(char *));
		if (!dst)
			return (NULL);
		dst[0] = NULL;
		return (dst);
	}
	dst = malloc((count_sep(s, c) + 1) * sizeof(char *));
	if (!dst)
		return (NULL);
	return (insert(dst, s, c));
}
