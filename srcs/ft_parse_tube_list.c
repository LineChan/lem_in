/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_tube_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 14:40:10 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/30 15:41:48 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Set up the adjency list with the tubes' list
**
** 1st parameter : line to be checked
*/
int				ft_test(const int ref_1, const int ref_2)
{
	static int		**ptr;
	int				n;

	ft_printf("ref_1 : %d ref_2 : %d\n", ref_1, ref_2);

	if (!ptr)
	{
		n = 0;
		if (!(ptr = ft_memalloc(sizeof(int) * ROOM_NB)))
			ft_exit(11);
		while (n < ROOM_NB)
			ptr[n++] = ft_memalloc(sizeof(int) * ROOM_NB);
		ft_printf("ft_test !\n");
	}
	(*(*ptr + 1)) + 1 = 9;
	return ((*(*ptr + 1) + 1));

}
int				ft_parse_tube_list(char **line, int depth)
{
	int		len;
	//t_lst	*node1;
	//t_lst	*node2;

	ft_print_parsing(depth, "tube_list", *line);
	if (!*line)
		ft_exit(8);
	len = 0;
	int test;
	test = ft_test(0, 0);
	ft_printf("test : %d\n", test);
#if 0
	
	char	*tmp_name;
	len = ft_parse_room_name(*line, depth + 1);
	tmp_name =  ft_strndup(*line, len);
	ft_printf("tmp_name : %s\n", tmp_name);
	ft_memdel((void **)tmp_name);
#endif
	return (1);
}
