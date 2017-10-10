/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_solution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 00:37:22 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/03 16:26:13 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Write the solution when the ##start and ##end rooms are directly connected
*/

void			ft_quick_solution(char **line)
{
	int		ret;
	char	*name;

	ret = 0;
	name = ft_strdup(R_NAME(ft_find_room_with_ref(&PATH(SHORTEST_PATH.next),
																	END_REF)));
	while ((*line = ft_gnt(FD, '\n')))
		ft_fprintf(FD, "%s\n", *line);
	ft_print_output();
	while (ret < ANT_NB)
		ft_fprintf(FD, "L%d-%s ", ++ret, name);
	ft_strdel(&name);
}
