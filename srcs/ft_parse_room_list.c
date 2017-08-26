/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_room_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 20:35:24 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/26 17:46:16 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Check if the line is a room
*/
int				ft_parse_room_list(char **line)
{
	ft_printf("{YELLOW:START} : ft_parse_room_list ---> '%s'\n", *line);
	if (ft_parse_room_id(line))
	{
		ft_printf("   {YELLOW:START} : ft_parse_room_list ---> comment\n");
		if ('#' == **line)
		{
			if ((*line = ft_fgnt("test.txt", '\n')))
				ft_parse_room_list(line);
		}
		else
			return (1);
	}
	else
	{
		if ((*line = ft_fgnt("test.txt", '\n')))
			ft_parse_room_list(line);
	}
#if 0
	while (*line)
	{
		ft_parse_new_line(*line);
		ft_parse_room_id(line);
		*line = ft_fgnt("test.txt", '\n');
	}
#endif
	ft_printf("{YELLOW:END  } : ft_parse_room_list\n");
	return (0);
}
