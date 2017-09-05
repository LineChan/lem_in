/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_ant.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 23:01:57 by mvillemi          #+#    #+#             */
/*   Updated: 2017/09/05 17:48:29 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Check if if the line is an ant
**
** 1st parameter : line to check
*/
void			ft_parse_ant(char **line, int depth)
{
	ft_parse_new_line(line);
	ft_print_parsing(depth, "parse_ant", *line);
	if (0 > (ANT_NB = ft_parse_nb(line, depth + 1)))
		ft_exit(1);
	if (ft_strlen(*line))
		ft_exit(1);
	ft_parse_new_line(line);
}
