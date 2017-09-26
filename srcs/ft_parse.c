/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 16:16:33 by mvillemi          #+#    #+#             */
/*   Updated: 2017/09/26 16:46:00 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Parse stdin, return 1 if the input is correct
*/
int				ft_parse(void)
{
	char	*line;
	int		depth;

	depth = 0;
	line = NULL;
	ft_parse_ant(&line, depth + 1);
	line = ft_gnt(0, '\n');
	if (!*line)
		ft_parse_new_line(&line);
	depth ^= depth;
	ft_parse_room_list(&line, depth + 1);
	depth ^= depth;
	ft_parse_tube_list(&line, depth + 1);
	while ((line = ft_gnt(0, '\n')))
			ft_printf("%s\n", line);
	ft_clear_unlinked_room();
	return (0);
}
