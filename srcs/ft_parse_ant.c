/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_ant.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 23:01:57 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/25 20:34:41 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Check if if the line is an ant
**
** 1st parameter : line to check
*/
void			ft_parse_ant(void)
{
	int			nb;
	char		*line;

	ft_printf("      {YELLOW:START} : ft_parse_ant\n");
	while ((line = ft_fgnt("test.txt", '\n')))
		if (!ft_parse_new_line(line))
			break ;
	nb = ft_parse_nb(&line);
	while ((line = ft_fgnt("test.txt", '\n')))
		if (!ft_parse_new_line(line))
			break ;
	ft_printf("      {YELLOW:END  } : ft_parse_ant ---> '%s'\n", line);
}
