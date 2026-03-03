/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misasant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 17:20:33 by misasant          #+#    #+#             */
/*   Updated: 2026/01/13 17:26:35 by misasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;
	size_t	total;

	if (count == 0 || size == 0)
		return (malloc(1));
	if (count > SIZE_MAX / size)
		return (NULL);
	total = count * size;
	mem = malloc(total);
	if (!mem)
		return (NULL);
	ft_bzero(mem, total);
	return (mem);
}
