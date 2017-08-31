/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_tube_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 14:40:10 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/31 15:13:22 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Set up the adjency list with the tubes' list
**
** 1st parameter : line to be checked
*/
void			ft_parse_tube_list(char **line, int depth)
{
	int		ref_1;
	int		ref_2;

	ft_print_parsing(depth, "tube_list", *line);
	if (!*line)
		ft_exit(8);
	if (!ft_parse_tube_id(*line, &ref_1, &ref_2, depth + 1))
		return ;
	ft_printf("ref_1 : %d ref_2 : %d\n", ref_1, ref_2);
	ft_printf("value : %d\n", ft_get_matrix(ref_1, ref_2));
	ft_set_matrix(ref_1, ref_2, 1);
	ft_printf("value : %d\n", ft_get_matrix(ref_1, ref_2));
}
