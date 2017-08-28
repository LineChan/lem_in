/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_room_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 12:51:46 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/28 12:54:45 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Print a rooms' list
**
** 1st parameter : head of the list to be printed
*/
void			ft_print_room_list(t_lst *head)
{
	t_lst	*it;

	it = head->next;
	while (it != head)
	{
		ft_printf("Name : '%s', ref : %d, x : %d, y : %d\n", R_NAME(it), R_REF(it), R_X(it), R_Y(it));
		it = it->next;
	}
}
