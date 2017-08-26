/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_room_name.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 21:03:25 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/26 16:47:36 by mvillemi         ###   ########.fr       */
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
	ft_parse_first_letter(*line);
	size = ft_parse_letter(*line);
	ft_add_room(*line, size);
	ft_printf("           {YELLOW:END  } : ft_parse_room_name ---> '%s'\n", R_NAME(ANTHILL.prev));
	return (size);
}
