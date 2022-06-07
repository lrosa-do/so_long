/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosa-do <lrosa-do@student.42lisboa>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 21:30:12 by lrosa-do          #+#    #+#             */
/*   Updated: 2022/05/29 11:41:38 by lrosa-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*dest;
	size_t			i;

	dest = s;
	i = 0;
	while (i++ < n)
		*dest++ = 0;
}

void	*ft_malloc(size_t count)
{	
	void	*dst;

	dst = malloc(count);
	if (!dst)
		return (NULL);
	ft_bzero(dst, count);
	return (dst);
}
