/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 16:16:33 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/24 16:50:03 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Parse stdin, return 1 if the input is correct
**
** 1st parameter : line to parse
*/
int			ft_parse(char *line)
{
	ft_printf("{YELLOW:START} : ft_parse{YELLOW: -->} \"%s\"\n", line);
	ft_printf("{YELLOW:END} : ft_parse {RED:KO}\n");
	return (0);
	ft_printf("{YELLOW:END : ft_parse {GREEN:OK}\n");
	return (1);
}
