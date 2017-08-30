/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 17:28:10 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/30 17:41:13 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** All adjancy matrix related functions
*/
int					**matrix(void)
{
	static int		**ptr;
	int				n;

	if (!ptr)
	{
		n = 0;
		if (!(ptr = (int **)ft_memalloc(sizeof(int *) * ROOM_NB)))
			ft_exit(11);
		while (n < ROOM_NB)
			if (!(ptr[n++] = ft_memalloc(sizeof(int) * ROOM_NB)))
				ft_exit(11);
	}
	return (ptr);
}

int					ft_get_matrix(const int ref_1, const int ref_2)
{
	return (MATRIX[ref_1][ref_2]);
}

void				ft_set_matrix(const int ref_1,
									const int ref_2,
									const int value)
{
	MATRIX[ref_1][ref_2] = value;
	MATRIX[ref_2][ref_1] = value;
}

void				ft_del_matrix(void)
{
	int			**ptr;
	int			n;

	ptr = MATRIX;
	n = 0;
	while (n < ROOM_NB)
		ft_memdel((void **)ptr[n++]);
	ft_memdel((void **)ptr);
}
