/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-bouh <kid-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 18:54:32 by kid-bouh          #+#    #+#             */
/*   Updated: 2021/11/08 18:46:38 by kid-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_nbr(long long n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	if (n < 0)
		n = n * (-1);
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static char	*calcul(long long nb, char *nbr, int len)
{
	int	sign;

	sign = 0;
	if (nb < 0)
	{
		sign = 1;
		nb = nb * (-1);
	}
	else if (nb == 0)
		nbr[0] = '0';
	nbr[len] = '\0';
	while (len--)
	{
		nbr[len] = nb % 10 + '0';
		nb /= 10;
	}
	if (sign == 1)
		nbr[0] = '-';
	return (nbr);
}

char	*ft_itoa(int n)
{
	char		*nbr;
	long long	nb;
	int			len;

	nb = n;
	len = count_nbr(nb);
	nbr = malloc(len + 1 * sizeof(char));
	if (!nbr)
		return (NULL);
	return (calcul(nb, nbr, len));
}
