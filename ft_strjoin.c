/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-bouh <kid-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 21:40:07 by kid-bouh          #+#    #+#             */
/*   Updated: 2021/11/05 12:11:03 by kid-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	p = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!p)
		return (NULL);
	i = 0;
	while (((char *)s1)[i])
	{
		p[i] = ((char *)s1)[i];
		i++;
	}
	j = 0;
	while (((char *)s2)[j])
	{
		p[i + j] = ((char *)s2)[j];
		j++;
	}
	p[i + j] = '\0';
	return (p);
}
