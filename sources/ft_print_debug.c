/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_shortest_path_list.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 10:52:50 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/17 13:21:05 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Print the shortest paths' list
*/

static void		ft_print_room_list(t_lst *head)
{
	t_lst		*it;

	it = head->next;
	while (it != head)
	{
		ft_printf("-%s- ", R_NAME(it));
		it = it->next;
	}
	write(1, "\n", 1);
}

void			ft_print_shortest_path_list(void)
{
	t_lst		*it;

	it = SHORTEST_PATH.next;
	write(1, "\n", 1);
	while (it != &SHORTEST_PATH)
	{
		ft_printf("[ {YELLOW:%d} ] %-5d", PATH_REF(it), PATH_LEN(it));
		ft_print_room_list(&PATH(it));
		it = it->next;
	}
}

void			ft_print_parsing(int depth,
									const char *name,
									const char *line)
{
	while (--depth)
		write(1, "\t", 1);
	if (line && ft_strlen(line))
		ft_printf("< {YELLOW:%s} > ---> %s\n", name, line);
	else
		ft_printf("< {YELLOW:%s} > \n", name);
}
