/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_room_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 20:35:24 by mvillemi          #+#    #+#             */
/*   Updated: 2017/09/05 17:38:28 by mvillemi         ###   ########.fr       */
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
	int			flag;

	flag = 0;
	ft_print_parsing(depth, "room_list", *line);
	ret = 1;
	if (!*line)
		ft_exit(6);
	while (ret && *line)
	{
		ret ^= ret;
		if (**line == '#')
		{
			if (*(*line + 1) == '#')
				ft_parse_command(line, depth + 1, &flag);
			ret = 1;
		}
		if (!ret)
		{
			ret = ft_parse_room_id(*line, &x, &y, depth + 1);
			if (IS_NEG(ret))
				break ;
			ft_add_room(*line, ret, x, y);
		}
		ft_parse_new_line(line);
	}
	if (!((flag & FLAG_START) && (flag & FLAG_END)))
		ft_exit(12);
	return (0);
}
