/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosa-do <lrosa-do@student.42lisboa>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:45:43 by lrosa-do          #+#    #+#             */
/*   Updated: 2022/03/14 19:21:09 by lrosa-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_print_str(char *str)
{
	int	len;

	len = 6;
	if (!str)
	{
		write (1, "(null)", len);
		return (len);
	}
	len = ft_strlen(str);
	write (1, str, len);
	return (len);
}
