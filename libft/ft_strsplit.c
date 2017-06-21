/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 15:55:35 by jpfeffer          #+#    #+#             */
/*   Updated: 2016/09/30 21:53:30 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(char const *str, char delim)
{
	int i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] == delim)
		{
			i++;
			if (str[i] == '\0')
				return (words);
		}
		words++;
		while (str[i] != delim)
		{
			i++;
			if (str[i] == '\0')
				return (words);
		}
	}
	return (words);
}

static int	ft_wordlength(char const *str, char delim)
{
	int	length;

	length = 0;
	while (*str != delim && *str)
	{
		length++;
		str++;
	}
	return (length);
}

static void	ft_quotes(char const **s, char ***str, int *j, int *k)
{
	if (**s == '\"')
	{
		(*s)++;
		while (**s && **s != '\"')
			(*str)[*j][(*k)++] = *((*s)++);
		(*s)++;
	}
	else if (**s == '\'')
	{
		(*s)++;
		while (**s && **s != '\'')
			(*str)[*j][(*k)++] = *((*s)++);
		(*s)++;
	}
}

char		**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		j;
	int		k;
	int		wc;

	j = 0;
	wc = ft_wordcount(s, c);
	if (!(str = (char**)ft_memalloc(sizeof(char*) * (wc + 1))))
		return (0);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (!(str[j] = ft_strnew(sizeof(char) * ft_wordlength(s, c))))
			return (0);
		k = 0;
		if (*s == '\"' || *s == '\'')
			ft_quotes(&s, &str, &j, &k);
		else
			while (*s && *s != c)
				str[j][k++] = *(s++);
		j++;
	}
	str[wc] = 0;
	return (str);
}
