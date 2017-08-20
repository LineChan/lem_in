/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_singl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:10:13 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/20 16:18:59 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Singleton functions
*/
t_anthill		*anthill(void)
{
	static t_anthill	*ptr = 0;

	if (!ptr && (ptr = ft_memalloc(sizeof(t_anthill))))
	{
		INIT_LST_HEAD(ptr->lst_head);
		ptr->room_nb = 0;
		ptr->ant_nb = 0;
		ptr->tube_nb = 0;
		ptr->start = 0;
		ptr->end = 0;
	}
	return (ptr);
}
