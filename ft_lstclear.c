/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamouri <ylamouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:02:00 by ylamouri          #+#    #+#             */
/*   Updated: 2023/10/25 11:02:00 by ylamouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*lst2;

	if (!*lst)
		return ;
	while (*lst)
	{
		lst2 = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = lst2;
	}
	*lst = 0;
}
