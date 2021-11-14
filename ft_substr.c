/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-bouh <kid-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 20:01:49 by kid-bouh          #+#    #+#             */
/*   Updated: 2021/11/11 22:51:41 by kid-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	int		i;

	if (!s)
		return (NULL);
	if (ft_strlen(s + start) < len)
		p = malloc((ft_strlen(s + start) + 1) * sizeof(char));
	else
		p = malloc(((int)len + 1) * sizeof(char));
	if (!p)
		return (NULL);
	i = 0;
	while (s[start] && i < (int)len && ft_strlen(s) >= start)
		p[i++] = s[start++];
	p[i] = '\0';
	return (p);
}
