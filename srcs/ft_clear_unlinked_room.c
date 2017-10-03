/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_unlinked_room.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 16:52:21 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/03 18:04:29 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Remove unlinked rooms from anthill
*/

void			ft_remove_room(int *i)
{
	t_lst	*node;

	node = ft_find_room_with_ref(&ANTHILL, *i);
	if (node)
	{
		if (!(R_REF(node) ^ END_REF) || !(R_REF(node) ^ START_REF))
		{
			ft_del_everything();
			EXIT_FAIL("ERROR");
		}
		ft_del_room(node);
	}
}

void			ft_clear_unlinked_room(void)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < ROOM_NB)
	{
		while (j < ROOM_NB)
		{
			if ((MATRIX[i][j] == 1) || (MATRIX[j][i] == 1))
				break ;
			++j;
			if (!(j ^ ROOM_NB))
				ft_remove_room(&i);
		}
		j ^= j;
		++i;
	}
}
