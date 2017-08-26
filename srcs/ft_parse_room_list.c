/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_room_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 20:35:24 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/26 22:29:08 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Check if the line is a room
*/
int				ft_parse_room_list(char **line)
{
	int		ret;
	char	*cursor;

	ret = 1;
	ft_printf("{YELLOW:START} ft_parse_room_list --> '%s'\n", *line);
	while (ret)
	{
		cursor = *line;
		if (!(ret = ft_parse_room_id(*line, cursor)))
		{
			cursor = *line;
		}
		else
		{
			//ft_add_room(
		}
	}
#if 0
	while (ft_parse_room_id(line) || (**line == '#') || ft_parse_new_line(line))
	{
		*line = ft_fgnt("test.txt", '\n');
		getchar();
	}
#endif
	ft_printf("{YELLOW:END  } ft_parse_room_list --> '%s'\n", *line);
	return (0);
}
