/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-bouh <kid-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:28:55 by kid-bouh          #+#    #+#             */
/*   Updated: 2021/11/12 10:12:51 by kid-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_check_left(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (set[j])
	{
		if (s1[i] == set[j])
		{
			j = 0;
			i++;
		}
		else
			j++;
	}
	return ((char *)&s1[i]);
}

int	ft_check_right(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = ft_strlen(s1) - 1;
	j = 0;
	while (set[j])
	{
		if (s1[i] == set[j])
		{
			j = 0;
			i--;
		}
		else
			j++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	char	*src;
	int		i;
	int		len;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	src = ft_check_left(s1, set);
	len = ft_check_right(src, set);
	while (src[i] && i <= len)
		i++;
	p = malloc((i + 1) * sizeof(char));
	if (!p)
		return (NULL);
	ft_memcpy(p, src, i);
	p[i] = '\0';
	return (p);
}
