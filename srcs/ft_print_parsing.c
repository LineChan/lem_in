/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 18:27:23 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/03 16:35:09 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Print parsing
**
** 1st parameter : recursivity depth
** 2nd parameter : function's name
** 3rd parameter : input line
*/

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
