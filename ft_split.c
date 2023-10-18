/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/10/18 15:50:02 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strndup(const char *s, size_t n)
{
	size_t	len;
	char	*dst;

	len = 0;
	while (len < n && s[len])
		len++;
	dst = malloc(len + 1);
	if (dst)
		ft_strlcpy(dst, s, len + 1);
	return (dst);
}

static size_t	ft_count_split(char const *s, char c)
{
	size_t	split_count;
	size_t	len;

	split_count = 0;
	while (*s)
	{
		len = 0;
		while (s[len] && s[len] != c)
			len++;
		if (len)
			split_count++;
		else
			s++;
		s += len;
	}
	return (split_count);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	len;
	size_t	split_count;
	char	**split;

	split_count = ft_count_split(s, c);
	split = malloc((split_count + 1) * sizeof(char *));
	if (split)
	{
		i = 0;
		while (i < split_count)
		{
			len = 0;
			while (s[len] && s[len] != c)
				len++;
			if (len)
				split[i++] = ft_strndup(s, len);
			s += len + 1;
		}
		split[i] = NULL;
	}
	return (split);
}
