/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feel-idr <feel-idr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 17:54:26 by feel-idr          #+#    #+#             */
/*   Updated: 2025/11/15 17:54:27 by feel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

int	ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (s[i] == c)
		return (i);
	return (-1);
}

char	*ft_calloc(int	count, int	size)
{
	char	*allo;
	int		i;
	int		len;

	len	= count * size;
	allo = (char *)malloc(len);
	if (allo == 0)
		return (0);
	i = 0;
	while (len-- > 0)
		allo[i++] = 0;
	return (allo);
}
char	*ft_strjoin(char *s1, char *s2)
{
	char	*allocat;
	int		i;
	int		j;
	int 	len;

	i = 0;
	j = 0;
	len = ft_strlen(s1);
	allocat = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!s1 || !s2 || !allocat)
		return (NULL);
	while (i < len)
	{
		allocat[i] = s1[i];
		i++;
	}
	len = ft_strlen(s2);
	while (j < len)
		allocat[i++] = s2[j++];
	allocat[i] = '\0';
	free(s1);
	return (allocat);
}

char	*ft_substr(char *s, int start, int end)
{
	char	*ptr;
	int		i;
	int		len;

	len = ft_strlen(s);
	i = 0;
	if (start < len)
	{
		ptr = (char *)malloc((end - start + 2) * sizeof(char));
		if (ptr == 0)
			return (0);
		while (start <= end)
		{
			ptr[i] = s[start];
			i++;
			start++;
		}
		ptr[i] = '\0';
		return (ptr);
	}
	return (NULL);
}
