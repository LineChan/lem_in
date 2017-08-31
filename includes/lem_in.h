/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 00:31:35 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/31 14:48:47 by mvillemi         ###   ########.fr       */
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
# define FD				(anthill()->fd)
# define ROOM_NB		(anthill()->room_nb)
# define ANT_NB			(anthill()->ant_nb)
# define TUBE_NB		(anthill()->tube_nb)
# define START_REF		(anthill()->start_ref)
# define END_REF		(anthill()->end_ref)

# define C_RESULT(it)	CONTAINEROF(it, t_result, lst)
# define PATH_REF(it)	(C_RESULT(it)->ref)
# define SHORTEST_PATH	(shortest_path()->result_head)
# define SP_NB			(shortest_path()->shortest_path_nb)

# define MATRIX			(matrix())
/*
** Flags
*/
# define FLAG_START		0x1
# define FLAG_END		0x10
# define COMMAND_START	(exist_already & FLAG_START)
# define COMMAND_END	(exist_already & FLAG_END)

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
	int			fd;
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
int					**matrix(void);
int					ft_get_matrix(const int ref_1, const int ref_2);
void				ft_set_matrix(const int ref_1,
									const int ref_2,
									const int value);
void				ft_del_matrix(void);
/*
int					adjancy(const int ref_1,
								const int ref_2,
								const int set,
								const int value);
								*/
void				ft_del_singl_anthill(void);
void				ft_del_singl_shortest_path(void);
void				ft_del_everything(void);
void				ft_add_room(const char *name,
								const size_t size,
								const int x,
								const int y);
void				ft_add_shortest_path(void);
void				ft_del_shortest_path(t_lst *path);
void				ft_del_room(t_lst *src);
void				ft_exit(const int ret);
void				ft_print_room_list(t_lst *head);
void				ft_print_parsing(const int depth,
									const char *name,
									const char *line);
int					ft_parse(void);
void				ft_parse_ant(char **line, int depth);
int					ft_parse_room_list(char **line, int depth);
void				ft_parse_tube_list(char **line, int depth);
int					ft_parse_room_id(char *line, int *x, int *y, int depth);
int					ft_parse_tube_id(char *line, int *ref_1, int *ref_2, int depth);
int					ft_parse_room_name(char *line, int depth);
void				ft_parse_first_letter(char *line, int depth);
int					ft_parse_letter(char *line, int depth);
int					ft_parse_new_line(char **line);
int					ft_parse_nb(char **cursor, int depth);
int					ft_parse_command(char **line, int depth);
int					ft_parse_gnt_and_save(char **line);
t_lst				*ft_parse_find_room(const char *room_name, const int len);
#endif
