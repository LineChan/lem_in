/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 16:16:33 by mvillemi          #+#    #+#             */
/*   Updated: 2017/09/04 14:52:53 by mvillemi         ###   ########.fr       */
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
	depth ^= depth;
	ft_parse_room_list(&line, depth + 1);
	depth ^= depth;
	ft_parse_tube_list(&line, depth + 1);
	ft_print_matrix();
	ft_clear_unlinked_room();
	return (0);
}
