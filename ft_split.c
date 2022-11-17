/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdarcour <jdarcour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:05:51 by jdarcour          #+#    #+#             */
/*   Updated: 2022/11/17 21:20:48 by jdarcour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	countwords(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (!(str[i] == c) && (str[i + 1] == c
				|| str[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

void	fill_words(char *tab, char *str, int lword)
{
	int	i;

	i = 0;
	while (i < lword)
	{
		tab[i] = str[i];
		i++;
	}
	tab[i] = '\0';
}

int	malloc_words(char **tab, char *str, char c)
{
	int		i;
	int		j;
	int		w;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] && str[i] == c)
			i++;
		if (str[i] && !(str[i] == c))
		{
			w = 0;
			while (str[i + w] && !(str[i + w] == c))
				w++;
			tab[j] = malloc(sizeof(char) * (w + 1));
			if (tab[j] == NULL)
				return (0);
			fill_words(tab[j], &str[i], w);
			j++;
			i += w;
		}
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	words_count;

	words_count = countwords((char *)s, c) + 1;
	tab = malloc(words_count * sizeof(char *));
	if (tab == NULL)
		return (0);
	if (malloc_words(tab, (char *)s, c) == 0)
	{
		while (words_count > 0)
		{
			free(tab[words_count]);
			words_count--;
		}
		return (0);
	}
	tab[words_count - 1] = 0;
	return (tab);
}
