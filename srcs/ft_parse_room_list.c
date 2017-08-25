/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_room_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 20:35:24 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/25 21:18:34 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Check if the line is a room
*/
void			ft_parse_room_list(void)
{
	char		*line;

	ft_printf("{YELLOW:START} : ft_parse_room_list\n");
	line = ft_fgnt("test.txt", '\n');
	ft_parse_room_id(&line);
	ft_printf("{YELLOW:END  } : ft_parse_room_list\n");
}
