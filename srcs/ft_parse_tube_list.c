/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_tube_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 14:40:10 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/30 17:41:41 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Set up the adjency list with the tubes' list
**
** 1st parameter : line to be checked
*/
int				ft_parse_tube_list(char **line, int depth)
{
	//int		len;
	//t_lst	*node1;
	//t_lst	*node2;

	ft_print_parsing(depth, "tube_list", *line);
	if (!*line)
		ft_exit(8);
#if 0

	char	*tmp_name;
	len = ft_parse_room_name(*line, depth + 1);
	tmp_name =  ft_strndup(*line, len);
	ft_printf("tmp_name : %s\n", tmp_name);
	ft_memdel((void **)tmp_name);
#endif
	return (1);
}
