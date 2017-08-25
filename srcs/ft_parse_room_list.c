/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_room_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 20:35:24 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/25 23:28:17 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Check if the line is a room
*/
void			ft_parse_room_list(char **line)
{
	//*line = ft_fgnt("test.txt", '\n');
	ft_printf("{YELLOW:START} : ft_parse_room_list ---> '%s'\n", *line);
	ft_parse_room_id(line);
	ft_printf("{YELLOW:END  } : ft_parse_room_list\n");
}
