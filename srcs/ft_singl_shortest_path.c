/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_singl_shortest_path.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 15:34:58 by mvillemi          #+#    #+#             */
/*   Updated: 2017/09/06 13:22:55 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** All shortest path related functions
*/

t_shortest_path			*shortest_path(void)
{
	static t_shortest_path		*ptr = 0;

	if (!ptr && (ptr = ft_memalloc(sizeof(t_shortest_path))))
		INIT_LST_HEAD(ptr->result_head);
	return (ptr);
}

void					ft_del_singl_shortest_path(void)
{
	t_shortest_path				*ptr;

	ptr = shortest_path();
	ft_lst_foreach(&(ptr->result_head), &ft_del_shortest_path);
	ft_memdel((void **)&ptr);
}
