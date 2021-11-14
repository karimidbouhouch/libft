/* ************************************************************************** */
/*                                                                      */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-bouh <kid-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:49:48 by kid-bouh          #+#    #+#             */
/*   Updated: 2021/11/03 11:28:24 by kid-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	size_t			i;

	i = 0;
	if (n > 0)
	{
		p = (unsigned char *)s;
		while (i < n)
		{
			p[i] = (unsigned char)c;
			i++;
		}
	}
	return (s);
}
