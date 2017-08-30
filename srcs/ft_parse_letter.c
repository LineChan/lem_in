/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_letter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 00:30:45 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/30 14:07:07 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Check if there are letters in the input
*/
int					ft_parse_letter(char *line, int depth)
{
	size_t		count;

	ft_print_parsing(depth, "parse_letter", "");
	count = 0;
	while (ft_isalpha(*line) || (*line == '_') || ft_isdigit(*line))
	{
		++line;
		++count;
	}
	return (count);
}
