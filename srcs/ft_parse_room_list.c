/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_room_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 20:35:24 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/28 00:06:00 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Check if the line is a room
*/
int				ft_parse_room_list(char **line)
{
	int			ret;
	int			x;
	int			y;

	ret = 1;
	ft_printf("{YELLOW:START} ft_parse_room_list --> '%s'\n", *line);
	if (!*line)
		ft_exit(6);
	//while (--ret >= 0)
	{
		ft_printf("--{YELLOW:START} ft_parse_room_list --> '%s'\n", *line);
		if (**line == '#')
		{
			if (*(*line + 1) == '#')
			{
				ret = (int)ft_parse_comment(*line);
			}
#if 0
			else if ( /* command*/)
			{
			}
			
#endif
		}
		if (!ret)
		{
			if (!(ret = (int)ft_parse_room_id(*line, &x, &y )))
				ft_exit(6);
			ft_add_room(*line, ret);
			++ROOM_NB;
			R_X(ANTHILL.prev) = x;
			R_Y(ANTHILL.prev) = y;
		}
		else
		{
			ret ^= ret;
		}
		//ft_printf("{YELLOW:IN   } ft_parse_room_list --> '%s'\n", *line);
		ft_parse_new_line(line);
		//ft_printf("{YELLOW:IN   } ft_parse_room_list --> '%s'\n", *line);
		//ft_printf("--{YELLOW:START} ft_parse_room_list --> '%s'\n", *line);
		ft_printf("--{YELLOW:END  } ft_parse_room_list --> '%s'\n", *line);
	}
	ft_printf("{YELLOW:END  } ft_parse_room_list --> '%s'\n", *line);
	return (0);
}