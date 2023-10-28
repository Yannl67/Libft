/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamouri <ylamouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:27:42 by ylamouri          #+#    #+#             */
/*   Updated: 2023/10/25 16:22:43 by ylamouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*str;
	size_t	len;

	len = nmemb * size;
	str = malloc(len);
	if (!str)
		return (NULL);
	ft_memset(str, 0, len);
	return (str);
}
