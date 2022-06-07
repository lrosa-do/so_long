/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosa-do <lrosa-do@student.42lisboa>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:44:33 by lrosa-do          #+#    #+#             */
/*   Updated: 2022/05/29 11:26:18 by lrosa-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_endl(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		return (1);
	return (0);
}

static char	*get_line(char **buffer_storage)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer_storage)
		return (NULL);
	while ((*buffer_storage)[i] != '\0' && (*buffer_storage)[i] != '\n')
		i++;
	line = ft_substr(*buffer_storage, 0, i + is_endl(*buffer_storage));
	if (!line)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

static char	*get_storage(char **buffer_storage)
{
	char	*backup;
	int		i;

	i = 0;
	if (!buffer_storage)
		return (NULL);
	while ((*buffer_storage)[i] != '\0' && (*buffer_storage)[i] != '\n')
		i++;
	if ((*buffer_storage)[i] == '\0')
	{
		free(*buffer_storage);
		return (NULL);
	}
	backup = ft_substr(*buffer_storage, i + 1, ft_strlen(*buffer_storage) - i);
	if (!backup)
	{
		free(backup);
		return (NULL);
	}
	free(*buffer_storage);
	return (backup);
}

static int	read_line(int fd, char **buffer, char **buffer_storage, char **line)
{
	int		bytes_read;
	char	*holder;

	bytes_read = 1;
	while (is_endl(*buffer_storage) != 1 && bytes_read > 0)
	{
		bytes_read = read(fd, *buffer, BUFFER_SIZE);
		(*buffer)[bytes_read] = '\0';
		holder = *buffer_storage;
		*buffer_storage = ft_strjoin(holder, *buffer);
		free(holder);
	}
	free(*buffer);
	*line = get_line(buffer_storage);
	if (**line == '\0')
	{
		free(*line);
		*line = NULL;
	}
	*buffer_storage = get_storage(buffer_storage);
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*buffer_storage;
	char		*line;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)ft_malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (read(fd, buffer, 0) < 0)
	{
		free(buffer);
		return (NULL);
	}
	if (!buffer_storage)
		buffer_storage = ft_strdup("");
	bytes_read = read_line(fd, &buffer, &buffer_storage, &line);
	if (bytes_read == 0 && !line)
		return (NULL);
	return (line);
}
