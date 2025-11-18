/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feel-idr <feel-idr@student.42.fr           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:48:10 by feel-idr          #+#    #+#             */
/*   Updated: 2025/11/16 17:53:40 by feel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_strdub(char *str)
{
	char	*src;
	int		len;
	int		i;

	i = 0;
	len = ft_sln(str);
	src = (char *)malloc (len + 1);
	while (len >= i)
	{
		src[i] = str[i];
		i++;
	}
	return (src);
}

static char	*ft_read_file(int fd, char *line_of_file)
{
	char	*line_added;
	int		i;

	if (!line_of_file)
		line_of_file = ft_calloc(1, 1);
	line_added = ft_calloc(BUFFER_SIZE + 1, 1);
	i = 1;
	while (i > 0)
	{
		i = read (fd, line_added, BUFFER_SIZE);
		if ((line_added[0] == 0 && line_of_file[0] == 0) || i < 0)
		{
			free(line_added);
			free(line_of_file);
			return (0);
		}
		line_added[i] = '\0';
		line_of_file = ft_strjoin (line_of_file, line_added);
		if (ft_strchr(line_added, '\n') >= 0)
			break ;
	}
	free(line_added);
	return (line_of_file);
}

char	*get_next_line(int fd)
{
	static char	*stc[4096];
	char		*line;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE == 0)
		return (0);
	stc[fd] = ft_read_file(fd, stc[fd]);
	if (!stc[fd])
	{
		free(stc[fd]);
		return (NULL);
	}
	if (ft_strchr(stc[fd], '\n') >= 0)
	{
		line = ft_substr(stc[fd], 0, ft_strchr(stc[fd], '\n'));
		tmp = ft_substr(stc[fd], ft_strchr(stc[fd], '\n') + 1, ft_sln(stc[fd]));
		free(stc[fd]);
		stc[fd] = tmp;
		return (line);
	}
	line = ft_strdub(stc[fd]);
	free(stc[fd]);
	stc[fd] = 0;
	return (line);
}
