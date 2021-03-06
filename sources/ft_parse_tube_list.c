/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_tube_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 14:40:10 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/11 02:00:25 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Set up the adjency list with the tubes' list
**
** 1st parameter : input line
** 2nd parameter : parsing depth
** 3rd parameter : option
*/

static void		ft_exit_tube_list(void)
{
	ft_del_everything();
	EXIT_FAIL("ERROR");
}

void			ft_parse_tube_list(char **line, int depth)
{
	int		ret;
	int		ref[2];

	DEBUG_MODE ? ft_print_parsing(depth, "tube_list", "") : 0;
	ret = 1;
	if (!*line)
		ft_exit_tube_list();
	while (ret && *line)
	{
		ret ^= ret;
		if ((**line == '#') && (ret = 1))
			ft_fprintf(FD, "%s\n", *line);
		if (!ret)
		{
			ret = ft_parse_tube_id(*line, ref, depth + 1);
			if (!ret)
			{
				ft_fprintf(FD, "%s\n", *line);
				return ;
			}
			++TUBE_NB;
			ft_set_matrix(ref[0], ref[1], 1);
		}
		ft_parse_new_line(line);
	}
}
