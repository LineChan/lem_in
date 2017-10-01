/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_room_with_ref.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 16:44:20 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/01 21:40:50 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Remove unlinked rooms from anthill
**
** 1st parameter : loop up list
** 2nd parameter : room's reference
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
