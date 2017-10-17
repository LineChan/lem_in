/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 13:03:31 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/17 13:19:47 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Print functions
*/

void			ft_print_input(void)
{
	char	*ret;

	close(FD);
	FD = open("input.txt", O_RDONLY, 0666);
	while ((ret = ft_gnt(FD, '\n')))
		ft_printf("%s\n", ret);
}

static void		ft_print_room_output(t_lst *head)
{
	t_lst		*it;

	it = head->prev;
	while (it != head)
	{
		if (R_ANT(it))
			ft_printf("L%d-%s ", R_ANT(it), R_NAME(it));
		it = it->prev;
	}
}

void			ft_print_output(void)
{
	t_lst		*it;

	it = SHORTEST_PATH.next;
	write(1, "\n", 1);
	while (it != &SHORTEST_PATH)
	{
		ft_print_room_output(&C_RESULT(it)->room_head);
		it = it->next;
	}
}
