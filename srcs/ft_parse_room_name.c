/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_room_name.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 21:03:25 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/26 17:32:24 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Check if it is a room's name
*/
size_t			ft_parse_room_name(char **line)
{
	size_t		size;

	ft_printf("           {YELLOW:START} : ft_parse_room_name ---> '%s'\n", *line);
	if (ft_parse_first_letter(*line))
		return (-1);
	if (IS_NEG((int)(size = ft_parse_letter(*line))))
		return (-1);
	ft_add_room(*line, size);
	ft_printf("           {YELLOW:END  } : ft_parse_room_name ---> '%s'\n", R_NAME(ANTHILL.prev));
	return (size);
}
