/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/10/18 01:30:48 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nblen(int n)
{
	size_t	len;

	len = 1;
	if (n < 0)
	{
		len = 2;
		n = -n;
	}
	while (n / 10)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t	i;
	size_t	len;	
	char	*dst;

	len = ft_nblen(n);
	dst = malloc(len + 1);
	if (dst)
	{
		i = 0;
		if (n < 0)
		{
			i = 1;
			dst[0] = '-';
			n = -n;
		}
		dst[len] = 0;
		while (i < len--)
		{
			dst[len] = '0' + n % 10;
			n /= 10;
		}
	}
	return (dst);
}
