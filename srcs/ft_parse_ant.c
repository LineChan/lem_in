/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_ant.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 23:01:57 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/25 12:38:30 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Check if if the line is an ant
**
** 1st parameter : line to check
*/
int				ft_parse_ant(char *line)
{
	ft_exit(1);
	ft_printf("      {YELLOW:START} : ft_parse_ant\n");
	while ((line = ft_fgnt("test.txt", '\n')))
	{
		if (!ft_parse_new_line(line))
			break ;
	}
	ft_printf("      {YELLOW:END  } : ft_parse_ant {GREEN:OK}\n");
	return (1);
}