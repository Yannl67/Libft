/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:58:15 by ylamouri          #+#    #+#             */
/*   Updated: 2023/10/28 17:46:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

static int	ft_cntwords(char const *s, char c)
{
	int	i;
	int	cpt;

	cpt = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			cpt++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (cpt);
}

static int	ft_wordscpy(char const *str, char **final_str, size_t l, int i)
{
	final_str[i] = ft_substr(str, 0, l);
	if (!final_str[i])
	{
		while (i > 0)
		{
			i--;
			free(final_str[i]);
		}
		free(final_str);
		return (0);
	}
	return (1);
}

static char	**ft_splitwords(char const *str, char sep)
{
	char	**result;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	j = ft_cntwords(str, sep);
	result = ft_calloc(j + 1, sizeof(char *));
	if (!result)
		return (NULL);
	while (str[i] && k < ft_cntwords(str, sep))
	{
		while (str[i] && str[i] == sep)
			i++;
		j = i;
		while (str[i] && str[i] != sep)
			i++;
		if (i != j && !ft_wordscpy((char *)str + j, result, i - j, k++))
			return (NULL);
	}
	return (result);
}

char	**ft_split(char const *s, char c)
{
	if (!s)
		return (NULL);
	return (ft_splitwords((char *)s, c));
}
