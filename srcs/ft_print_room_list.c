/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_room_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 12:51:46 by mvillemi          #+#    #+#             */
/*   Updated: 2017/09/26 17:29:13 by mvillemi         ###   ########.fr       */
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
		ft_fprintf(2, "-%s- ", R_NAME(it));
		it = it->next;
	}
	write(2, "\n", 1);
}
