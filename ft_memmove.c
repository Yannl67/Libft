/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamouri <ylamouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:46:13 by ylamouri          #+#    #+#             */
/*   Updated: 2023/10/25 16:33:46 by ylamouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;

	d = (char *)dest;
	s = (const char *)src;
	i = 0;
	if (!d && !s)
		return (0);
	if (s < d)
	{
		while (n-- > 0)
			d[n] = s[n];
	}
	else
	{
		while (n > i)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}
