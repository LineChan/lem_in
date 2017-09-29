/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_letter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 00:30:45 by mvillemi          #+#    #+#             */
/*   Updated: 2017/09/29 00:52:04 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Check if there are letters in the input
*/
int					ft_parse_letter(char *line, int depth, int option[])
{
	size_t		count;

	option[0] ? ft_print_parsing(depth, "letter", "") : 0;
	count = 0;
	while (ft_isalpha(*line) || (*line == '_') || ft_isdigit(*line))
	{
		++line;
		++count;
	}
	return (count);
}
