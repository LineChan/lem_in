/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_room_id.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 20:50:22 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/26 22:35:05 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Check if there is a room id
**
** 1st parameter : line to be checked
*/
int					ft_parse_room_id(char *line, char *cursor)
{
	int		len;

	ft_printf("----{YELLOW:START} ft_parse_room_id --> '%s'\n", line);
	if (!(len = ft_parse_room_name(line)))
		return (0);
	cursor = line + len;
	ft_parse_nb(&cursor);
	if (++*cursor != ' ') 
	{
		ft_exit(3);
	}
	ft_printf("----{YELLOW:END  } ft_parse_room_id --> '%s'\n", cursor);
	ft_printf("----{YELLOW:END  } ft_parse_room_id --> '%s'\n", R_NAME(ANTHILL.prev));
	//ft_add_room(*line, len);
	return (len);
}
