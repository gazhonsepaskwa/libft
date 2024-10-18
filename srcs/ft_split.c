/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:28:31 by nalebrun          #+#    #+#             */
/*   Updated: 2024/10/18 14:18:35 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	count_words(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static char	*malloc_word(const char *s, char c)
{
	int		len;
	char	*word;
	int		i;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(const char *s, char c)
{
	char	**result;
	int		words;
	int		i;
	int		j;

	words = count_words(s, c);
	result = (char **)calloc((words + 1), sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] && j < words)
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			result[j] = malloc_word(s + i, c);
			if (!result[j])
				return (NULL);
			j++;
		}
		i++;
	}
	result[j] = NULL;
	return (result);
}
