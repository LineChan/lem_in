/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 00:31:35 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/26 22:35:07 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libs/libft/includes/libft.h"
# include "../libs/liblst/includes/liblst.h"

# define C_ROOM(it)		CONTAINEROF(it, t_room, lst)
# define R_REF(it)		(C_ROOM(it)->ref)
# define R_NAME(it)		(C_ROOM(it)->name)
# define R_SIZE(it)		(C_ROOM(it)->name_size)
# define R_X(it)		(C_ROOM(it)->x)
# define R_Y(it)		(C_ROOM(it)->y)
# define ANTHILL		(anthill()->room_head)
# define ROOM_NB		(anthill()->room_nb)
# define ANT_NB			(anthill()->ant_nb)
# define TUBE_NB		(anthill()->tube_nb)
# define START			(anthill()->start_ref)
# define END			(anthill()->end_ref)

# define C_RESULT(it)	CONTAINEROF(it, t_result, lst)
# define PATH_REF(it)	(C_RESULT(it)->ref)
# define SHORTEST_PATH	(shortest_path()->result_head)
# define SP_NB		(shortest_path()->shortest_path_nb)
/*
** Structures
*/

typedef struct			s_error
{
	const char		message[100];
}						t_error;

typedef struct			s_room
{
	int			ref;
	int			parent;
	int			x;
	int			y;
	char		*name;
	size_t		name_size;
	t_lst		lst;
}						t_room;

typedef struct			s_anthill
{
	int			room_nb;
	int			ant_nb;
	int			tube_nb;
	int			start_ref;
	int			end_ref;
	t_lst		room_head;
}						t_anthill;

typedef struct			s_shortest_path
{
	int		shortest_path_nb;
	t_lst	result_head;
}						t_shortest_path;

typedef struct			s_result
{
	int		ref;
	t_lst	lst;
	t_lst	room_head;
}						t_result;
/*
** Prototypes
*/
t_anthill			*anthill(void);
t_shortest_path		*shortest_path(void);
void				ft_del_singl_anthill(void);
void				ft_del_singl_shortest_path(void);
void				ft_add_room(const char *name, size_t size);
void				ft_add_shortest_path(void);
void				ft_del_shortest_path(t_lst *path);
void				ft_del_room(t_lst *src);
void				ft_exit(const int ret);

int					ft_parse(void);
void				ft_parse_ant(char **line);
int					ft_parse_room_list(char **line);
int					ft_parse_room_id(char *line, char *cursor);
int					ft_parse_room_name(char *line);
int					ft_parse_first_letter(char *line);
int					ft_parse_letter(char *line);
int					ft_parse_new_line(char **line);
int					ft_parse_nb(char **cursor);
#endif
