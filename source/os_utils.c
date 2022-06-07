/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   os_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosa-do <lrosa-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 20:51:26 by lrosa-do          #+#    #+#             */
/*   Updated: 2022/06/04 19:10:44 by lrosa-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_file_exists(char *str)
{
	int	fd;

	fd = open(str, O_RDWR);
	if (fd == -1)
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

const char	*ft_file_extension(const char *file_name)
{
	const char	*dot;

	dot = ft_strrchr(file_name, '.');
	if (!dot || dot == file_name)
		return (NULL);
	return (dot);
}

int	ft_isfile_extension(const char *file_name, const char *ext)
{
	if (ft_strncmp(ft_strchr(file_name, '.'), ext, 4) != 0)
		return (0);
	return (1);
}
