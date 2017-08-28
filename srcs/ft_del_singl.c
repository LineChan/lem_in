/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_singl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 15:05:38 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/28 12:59:43 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
/*
** Clean each list before freeing their head
*/
void		ft_del_singl_anthill(void)
{
	t_anthill		*ptr;

	ptr = anthill();
	ft_lst_foreach(&(ptr->room_head), &ft_del_room);
	ft_memdel((void **)&ptr);
}

void		ft_del_singl_shortest_path(void)
{
	t_shortest_path		*ptr;

	ptr = shortest_path();
	ft_lst_foreach(&(ptr->result_head), &ft_del_shortest_path);
	ft_memdel((void **)&ptr);
}
