/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 08:32:03 by jpfeffer          #+#    #+#             */
/*   Updated: 2016/12/01 08:32:03 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	fill_buffer(const int fd, char **line)
{
	char		buffer[BUFF_SIZE + 1];
	ssize_t		progress;
	char		*temp;

	progress = read(fd, buffer, BUFF_SIZE);
	if (progress < 0)
		return (-1);
	if (progress > 0)
	{
		buffer[progress] = '\0';
		if (!(temp = ft_strjoin(*line, buffer)))
			return (-1);
		free(*line);
		*line = temp;
		if (progress < BUFF_SIZE)
			return (0);
	}
	return (progress);
}

int		get_next_line(const int fd, char **line)
{
	static char	*temp = 0;
	char		*last;
	ssize_t		progress;

	if (!(temp) && (!(temp = (char*)ft_memalloc(sizeof(char)))))
		return (-1);
	last = ft_strchr(temp, '\n');
	while (last == '\0')
	{
		if ((progress = fill_buffer(fd, &temp)) < 0)
			return (-1);
		last = (progress > 0) ? ft_strchr(temp, '\n') : last;
		if (progress == 0 && (last = ft_strchr(temp, '\0')) == temp)
			return (0);
	}
	last = ft_strchr(temp, '\n') ? ft_strchr(temp, '\n') : last;
	if (!(*line = ft_strsub(temp, 0, (last - temp))))
		return (ft_error_handler(-1, temp, NULL, NULL));
	last = *last ? last + 1 : last;
	last = ft_strdup(last);
	free(temp);
	if (!(temp = ft_strdup(last)))
		return (ft_error_handler(-1, last, NULL, NULL));
	free(last);
	return (1);
}
