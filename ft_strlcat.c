/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-bouh <kid-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:32:13 by kid-bouh          #+#    #+#             */
/*   Updated: 2021/11/04 11:26:08 by kid-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	t;

	t = ft_strlen(src);
	j = ft_strlen((const char *)dst);
	i = 0;
	if (size > j)
	{
		while (src[i] && i < size - j - 1)
		{
			dst[j + i] = src[i];
			i++;
		}
		dst[j + i] = '\0';
		return (j + t);
	}
	return (t + size);
}
