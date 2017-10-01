/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_last_room_to_path.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 13:58:31 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/01 21:21:15 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Copy the END room to the end of the lastest path
*/
void				ft_copy_end_room_to_path(void)
{
	t_room		*new;

	if (!(new = ft_memalloc(sizeof(t_room))))
	{
		ft_del_everything();
		EXIT_FAIL("ERROR");
	}
	new->name = ft_strndup(R_NAME(ANTHILL.prev), R_SIZE(ANTHILL.prev));
	ft_memcpy(new, C_ROOM(ANTHILL.prev), R_SIZE(ANTHILL.prev));
	ft_lst_add_prev(&new->lst, &PATH(SHORTEST_PATH.prev));
}
