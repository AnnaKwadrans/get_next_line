/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 10:30:15 by akwadran          #+#    #+#             */
/*   Updated: 2024/11/25 01:33:03 by akwadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (src[i] && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strdup(const char *s)
{
	int		len;
	char	*ptr;

	len = ft_strlen(s) + 1;
	ptr = malloc(sizeof(char) * len);
	if (ptr == NULL)
		return (ptr);
	ft_strlcpy(ptr, s, sizeof(char) * len);
	return (ptr);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	char	*ptr;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(s1) + ft_strlen(s2);
	ptr = malloc(sizeof(char) * (len + 1));
	if (s1 == NULL || s2 == NULL || ptr == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] && i < len)
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j] && i < len)
	{
		ptr[i] = s2[j];
		i++;
		j++;
	}
	ptr[i] = '\0';
	free(s1);
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	substr_len;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		substr_len = 0;
	else if (ft_strlen(s) - start < len)
		substr_len = ft_strlen(s) - start;
	else
		substr_len = len;
	ptr = malloc((sizeof(char) * (substr_len + 1)));
	if (ptr == NULL)
		return (NULL);
	else
	{
		if (start >= ft_strlen(s))
			ft_strlcpy(ptr, "", substr_len + 1);
		else
			ft_strlcpy(ptr, s + start, substr_len + 1);
		return (ptr);
	}
}
