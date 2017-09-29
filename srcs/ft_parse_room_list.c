/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_room_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 20:35:24 by mvillemi          #+#    #+#             */
/*   Updated: 2017/09/29 12:01:53 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Set up the rooms' list
**
** 1st parameter : line to be checked
** 2nd parameter : dept
*/
int				ft_parse_room_list(char **line, int depth, int option[])
{
	int			ret;
	int			flag;
	int			coordinate[2];

	flag = 0;
	option[0] ? ft_print_parsing(depth, "room_list", *line): 0;
	ret = 1;
	if (!*line)
		ft_exit(6);
	while (ret && *line)
	{
		ret ^= ret;
		if (**line == '#')
		{
			if (*(*line + 1) == '#')
				ft_parse_command(line, depth + 1, &flag, option);
			ret = 1;
		}
		if (!ret)
		{
			ret = ft_parse_room_id(*line, coordinate, depth + 1, option);
			if (IS_NEG(ret))
				break ;
			ft_add_room(*line, ret, coordinate);
			ft_parse_duplicate_name_and_coordinate(*line, ret, coordinate);
		}
		if (IS_NEG(ft_parse_new_line(line)))
				break ;
	}
	if (!((flag & FLAG_START) && (flag & FLAG_END)))
		ft_exit(12);
	return (0);
}
