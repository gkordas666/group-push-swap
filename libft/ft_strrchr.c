/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misasant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 17:01:13 by misasant          #+#    #+#             */
/*   Updated: 2026/01/13 17:01:21 by misasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			len;
	unsigned char	ch;

	ch = (unsigned char)c;
	len = ft_strlen(s);
	while (1)
	{
		if ((unsigned char)s[len] == ch)
			return ((char *)(s + len));
		if (len == 0)
			break ;
		len--;
	}
	return (NULL);
}
