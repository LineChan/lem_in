/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_tube_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 14:40:10 by mvillemi          #+#    #+#             */
/*   Updated: 2017/09/08 15:37:23 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Set up the adjency list with the tubes' list
**
** 1st parameter : line to be checked
*/
void			ft_parse_tube_list(char **line, int depth)
{
	int		ret;
	int		ref_1;
	int		ref_2;

	ft_print_parsing(depth, "tube_list", "");
	ret = 1;
	if (!*line)
		ft_exit(8);
	while (ret && *line)
	{
		ret ^= ret;
		if (**line == '#')
		{
			ft_fprintf(FD, "%s\n", *line);
			ret = 1;
		}
		if (!ret)
		{
			ret = ft_parse_tube_id(*line, &ref_1, &ref_2, depth + 1);
			if (!ret)
				return ;
			++TUBE_NB;
			ft_set_matrix(ref_1, ref_2, 1);
		}
		ft_parse_new_line(line);
	}
}
