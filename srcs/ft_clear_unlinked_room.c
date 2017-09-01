/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_unlinked_room.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 16:52:21 by mvillemi          #+#    #+#             */
/*   Updated: 2017/09/01 16:36:51 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Remove unlinked rooms from anthill
*/
t_lst			*ft_find_room_with_ref(t_lst *head, const int ref)
{
	t_lst		*it;

	if (ft_lst_is_head(head))
		return (0);
	it = head->next;
	while (it != head)
	{
		if (!(ref ^ R_REF(it)))
			return (it);
		it = it->next;
	}
	return (0);
}
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
			if (MATRIX[i][j] == 1)
				break;
			++j;
			if (!(j ^ ROOM_NB))
			{
				node_tmp = ft_find_room_with_ref(&ANTHILL, i);
				if (!(R_REF(node_tmp) ^ END_REF) ||
						!(R_REF(node_tmp) ^ START_REF))
					ft_exit(12);
				ft_del_room(node_tmp);
			}
		}
		j ^= j;
		++i;
	}
}
