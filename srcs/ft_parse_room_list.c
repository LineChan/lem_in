/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_room_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 20:35:24 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/29 01:12:46 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
 ** Set up the rooms' list
 **
 ** 1st parameter : line to be checked
 */
int				ft_parse_room_list(char **line, int depth)
{
	int			ret;
	int			x;
	int			y;

	ft_print_parsing(depth, "room_list", "");
	ret = 1;
	if (!*line)
		ft_exit(6);
	while (ret && *line)
	{
#if 1
		ret ^= ret;
		if (**line == '#')
		{
			if (*(*line + 1) == '#')
			{
				ret = (int)ft_parse_comment(*line, depth + 1);
			}
			ret = 1;
		}
#endif
		if (!ret)
		{
			ret = ft_parse_room_id(*line, &x, &y, depth + 1);
			ft_add_room(*line, ret);
			++ROOM_NB;
			R_X(ANTHILL.prev) = x;
			R_Y(ANTHILL.prev) = y;
		}
		ft_parse_new_line(line);
	}
#if 0
	else
	{
		ret ^= ret;
	}
#endif
	return (0);
}
