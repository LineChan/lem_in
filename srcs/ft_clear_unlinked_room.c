/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_unlinked_room.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 16:52:21 by mvillemi          #+#    #+#             */
/*   Updated: 2017/09/22 11:42:36 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Remove unlinked rooms from anthill
*/
void			ft_clear_unlinked_room(void)
{
	int		i;
	int		j;
	t_lst	*node_tmp;

	i = 0;
	j = 0;
	while (i < ROOM_NB)
	{
		while (j < ROOM_NB)
		{
			if ((MATRIX[i][j] == 1) || (MATRIX[j][i] == 1))
				break;
			++j;
			if (!(j ^ ROOM_NB))
			{
				node_tmp = ft_find_room_with_ref(&ANTHILL, i);
				if (node_tmp)
				{
					if (!(R_REF(node_tmp) ^ END_REF) ||
							!(R_REF(node_tmp) ^ START_REF))
						ft_exit(12);
					ft_del_room(node_tmp);
				}
			}
		}
		j ^= j;
		++i;
	}
}
