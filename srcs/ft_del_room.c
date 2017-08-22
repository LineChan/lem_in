/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 16:39:30 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/22 11:30:28 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Delete a room
**
** 1st paremeter : room's node to be removed
*/
void			ft_del_room(t_lst *src)
{
	ft_lst_del(src);
	free((void *)R_NAME(src));
	free(C_ROOM(src));
}
