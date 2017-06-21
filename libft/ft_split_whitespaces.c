/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 12:41:00 by jpfeffer          #+#    #+#             */
/*   Updated: 2017/06/09 12:41:00 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static int	ft_wordlength(char const *str)
{
	int	length;

	length = 0;
	while (*str && *str != ' ' && *str != '\t')
	{
		length++;
		str++;
	}
	return (length);
}

static int	ft_wordcount(char const *str)
{
	int i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t')
		{
			i++;
			if (str[i] == '\0')
				return (words);
		}
		words++;
		while (str[i] != ' ' && str[i] != '\t')
		{
			i++;
			if (str[i] == '\0')
				return (words);
		}
	}
	return (words);
}

char		**ft_split_whitespaces(char const *s)
{
	char	**str;
	int		j;
	int		k;
	int		wc;

	j = 0;
	wc = ft_wordcount(s);
	if (!(str = (char**)ft_memalloc(sizeof(char*) * (wc + 1))))
		return (0);
	while (*s)
	{
		while (*s && (*s == ' ' || *s == '\t'))
			s++;
		if (!(str[j] = ft_strnew(sizeof(char) * ft_wordlength(s))))
			return (0);
		k = 0;
		if (*s == '\"' || *s == '\'')
			ft_quotes(&s, &str, &j, &k);
		else
			while (*s && *s != ' ' && *s != '\t')
				str[j][k++] = *(s++);
		j++;
	}
	str[wc] = 0;
	return (str);
}
