/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_shortest_path.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 19:40:57 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/22 20:35:54 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Free all the rooms on a given path
**
** 1st parameter : shortest path to be removed
*/
void		ft_del_shortest_path(t_result *path)
{
	ft_lst_del(&(path->lst));
	ft_lst_foreach(&(path->room_head), &ft_del_room);
	ft_memdel((void **)path);
}
