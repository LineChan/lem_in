/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_singl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 15:05:38 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/22 11:37:30 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_del_singl(void)
{
	t_anthill	*ptr;

	ptr = anthill();
	ft_lst_foreach(&(ptr->lst_head), &ft_del_room);
	ft_memdel((void **)&ptr);
}
