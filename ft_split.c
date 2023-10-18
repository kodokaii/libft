/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/10/18 20:43:52 by nlaerema         ###   ########.fr       */
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

static char	**ft_split_free(char **split, size_t i)
{
	while (i--)
		free(split[i]);
	free(split);
	return (NULL);
}

static char	*ft_find_next_split(char const *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	return ((char *)s);
}

static size_t	ft_split_count(char const *s, char c)
{
	size_t		split_count;
	char const	*current;

	current = s;
	split_count = 0;
	while (*current)
	{
		current = ft_find_next_split(s, c);
		if (0 < current - s)
			split_count++;
		s = current + 1;
	}
	return (split_count);
}

char	**ft_split(char const *s, char c)
{
	size_t		i;
	size_t		split_count;
	char const	*current;
	char		**split;

	split_count = ft_split_count(s, c);
	split = malloc((split_count + 1) * sizeof(char *));
	if (split)
	{
		i = 0;
		while (i < split_count)
		{
			current = ft_find_next_split(s, c);
			if (0 < current - s)
			{
				split[i] = ft_strndup(s, current - s);
				if (!split[i])
					return (ft_split_free(split, i));
				i++;
			}
			s = current + 1;
		}
		split[i] = NULL;
	}
	return (split);
}
