/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 18:13:26 by jpfeffer          #+#    #+#             */
/*   Updated: 2016/10/01 18:13:26 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*link;

	if (!(link = ft_memalloc(sizeof(t_list))))
		return (0);
	link->content = (void*)content;
	if (content)
	{
		if (!(link->content = ft_memalloc(content_size)))
			return (0);
		ft_memcpy(link->content, content, content_size);
		link->content_size = content_size;
	}
	else
	{
		link->content_size = 0;
		link->next = NULL;
	}
	return (link);
}
