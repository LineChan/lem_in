/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send_quick_solution.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 17:13:43 by mvillemi          #+#    #+#             */
/*   Updated: 2017/09/26 17:55:28 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Write the solution when the starting and the ending room are connected
*/

void			ft_send_quick_solution(void)
{
	int		nb;

	nb = 0;
	while (nb < ANT_NB)
		ft_printf("L%d-%s ", ++nb, R_NAME(PATH(SHORTEST_PATH.next).next));
	write(1, "\n", 1);
}
