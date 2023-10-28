/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamouri <ylamouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:02:26 by ylamouri          #+#    #+#             */
/*   Updated: 2023/10/25 11:02:26 by ylamouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	t_list	*add_node(t_list *content, void (*del)(void *))
{
	t_list	*new_mode;

	new_mode = ft_lstnew(content);
	if (!new_mode)
	{
		del(content);
		return (NULL);
	}
	return (new_mode);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*current;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	content = f(lst->content);
	new_lst = add_node(content, del);
	if (!new_lst)
		return (NULL);
	current = new_lst;
	lst = lst->next;
	while (lst)
	{
		content = f(lst->content);
		current->next = add_node(content, del);
		if (!current->next)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		current = current->next;
		lst = lst->next;
	}
	return (new_lst);
}
