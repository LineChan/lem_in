/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_room_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 20:35:24 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/11 02:26:33 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Set up the rooms' list
**
** 1st parameter : input line
** 2nd parameter : parsing dept
** 3rd parameter : option
*/

static int		ft_find_command(char **line, int depth, int *flag)
{
	if (!((**line == '#') && (*(*line + 1) == '#')))
		return (0);
	ft_parse_command(line, depth, flag);
	return (1);
}

static void		ft_exit_room_list(void)
{
	ft_del_everything();
	EXIT_FAIL("ERROR");
}

int				ft_parse_room_list(char **line, int depth)
{
	int			ret;
	int			flag;
	int			coordinate[2];

	flag = 0;
	DEBUG_MODE ? ft_print_parsing(depth, "room_list", *line) : 0;
	ret = 1;
	if (!*line)
		ft_exit_room_list();
	while (ret && *line)
	{
		if (!(ret = ft_find_command(line, depth + 1, &flag)))
		{
			if (IS_NEG((ret = ft_parse_room_id(*line, coordinate, depth + 1))))
				break ;
			ft_add_room(*line, ret, coordinate);
			ft_parse_duplicate_name_and_coordinate(*line, ret, coordinate);
		}
		if (IS_NEG(ft_parse_new_line(line)))
			break ;
	}
	if (!((flag & FLAG_START) && (flag & FLAG_END)))
		ft_exit_room_list();
	return (0);
}
