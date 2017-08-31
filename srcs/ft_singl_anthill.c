/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_singl_anthill.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 15:32:30 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/31 15:34:43 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** All anthill related functions
**
*/
t_anthill				*anthill(void)
{
	static t_anthill		*ptr = 0;

	if (!ptr && (ptr = ft_memalloc(sizeof(t_anthill))))
		INIT_LST_HEAD(ptr->room_head);
	return (ptr);
}

void					ft_del_singl_anthill(void)
{
	t_anthill				*ptr;

	ptr = anthill();
	ft_lst_foreach(&(ptr->room_head), &ft_del_room);
	ft_memdel((void **)&ptr);
}

