/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misasant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:43:34 by misasant          #+#    #+#             */
/*   Updated: 2026/01/13 17:01:03 by misasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t			i;
	unsigned char	ch;

	i = 0;
	ch = (unsigned char)c;
	while (str[i])
	{
		if ((unsigned char)str[i] == ch)
			return ((char *)(str + i));
		i++;
	}
	if (ch == '\0')
		return ((char *)(str + i));
	return (NULL);
}
