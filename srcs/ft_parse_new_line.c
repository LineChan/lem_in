/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_new_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 23:12:08 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/26 17:12:10 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Check if the line is a new line
**
** 1st paremter : line to be check
*/
int				ft_parse_new_line(char *line)
{
	ft_printf("        {YELLOW:START} : ft_parse_new_line ---> '%s'\n", line);
	if ((ft_strlen(line)))
	{
		ft_printf("        {YELLOW:END} new_line: {RED:KO}\n");
		return (0);
	}
	ft_printf("        {YELLOW:END} new_line: {GREEN:OK}\n");
	getchar();
	return (1);
}
