/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_ant.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 23:01:57 by mvillemi          #+#    #+#             */
/*   Updated: 2017/09/29 10:14:47 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Check if if the line is an ant
**
** 1st parameter : line from the input
** 2nd parameter : parsing depthto check
** 3rd parameter : options
*/
void			ft_parse_ant(char **line, int depth, int option[])
{
	ft_parse_new_line(line);
	option[0] ? ft_print_parsing(depth, "parse_ant", *line) : 0;
	if (0 > (ANT_NB = ft_parse_nb(line, depth + 1, option)))
		ft_exit(1);
	if (ft_strlen(*line) || !ANT_NB)
		ft_exit(1);
	ft_fprintf(FD, "%d\n", ANT_NB);
}
