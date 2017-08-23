/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_shortest_path.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 19:31:07 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/23 13:52:57 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
/*
** Add a possible shortest path the list
*/
void			ft_add_shortest_path(void)
{
	static int		ref = 0;
	t_result		*new;

	if (!(new = ft_memalloc(sizeof(t_result))))
		EXIT_FAIL("Failed memory allocation");
	INIT_LST_HEAD(new->room_head);
	new->ref = ref++;
	ft_lst_add_prev(&new->lst, &(shortest_path()->result_head));
}
