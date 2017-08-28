/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 18:27:23 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/28 18:47:52 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Print parsing
**
** 1st parameter : recursivity depth
** 2nd parameter : function's name
*/
void			ft_print_parsing(const int depth, 
									const char *name,
									const char *line)
{
	fprintf(stderr, "%*s", depth * 3, "");
	if (line && ft_strlen(line))
		ft_fprintf(2, "< {YELLOW:%s} > ---> %s\n", name, line);
	else
		ft_fprintf(2, "< {YELLOW:%s} > \n", name);
}
