/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_first_letter.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 21:07:24 by mvillemi          #+#    #+#             */
/*   Updated: 2017/09/29 00:51:41 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Check if there is a first letter
**
** 1st parameter : line to be checked
*/
void				ft_parse_first_letter(char *line, int depth, int option[])
{
	option[0] ? ft_print_parsing(depth, "first_letter", ""): 0;
	if (!(*line && 
			(((ft_isalpha(*line)) && (*line != 'L')) || ft_isdigit(*line))))
		ft_exit(6);
}
