/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_option.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 12:42:26 by mvillemi          #+#    #+#             */
/*   Updated: 2017/09/28 13:24:48 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Handle the parsing visual option
**
** 1st parameter : number of arguments
** 2nd parameter : list of arguments
** 3rd parameter : array to keep track of options
*/

void		ft_handle_option(int ac, char **av, int option[2])
{
	option[0] = 0;
	if (ac > 1)
	{
		--ac;
		++av;
		if (!ft_strcmp("--parsing", *av))
		{
			option[0] = 1;
			++av;
			--ac;
		}
		if (ac && !ft_strncmp("--shortest_path=" , *av, 16))
		{
			if (ft_strlen(*av) == 16)
				ft_exit(17);
			*av += 16;
			option[1] = ft_parse_nb(av, 0);
			ft_printf("{GREEN:HANDLE OPTION} : %d\n", option[1]);
		}
	}
}
