/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misasant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:04:34 by misasant          #+#    #+#             */
/*   Updated: 2026/01/14 17:10:10 by misasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cur;
	t_list	*next;

	if (!lst)
		return ;
	cur = *lst;
	while (cur)
	{
		next = cur->next;
		ft_lstdelone(cur, del);
		cur = next;
	}
	*lst = NULL;
}
