/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_room_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 12:51:46 by mvillemi          #+#    #+#             */
/*   Updated: 2017/09/05 16:17:19 by mvillemi         ###   ########.fr       */
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
		ft_fprintf(1, "-%s- ", R_NAME(it));
		it = it->next;
	}
	write(1, "\n", 1);
}
