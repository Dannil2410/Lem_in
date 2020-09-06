/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 12:30:49 by tstripeb          #+#    #+#             */
/*   Updated: 2020/02/26 14:30:06 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft.h"

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

typedef struct		s_rooms
{
	char			*name;
	int				x;
	int				y;
	int				distance;
	t_list			*links;
	struct s_rooms	*parent;
	struct s_rooms	*pred;
	struct s_rooms	*succ;
	struct s_rooms	*bests;
}					t_rooms;

typedef struct		s_links
{
	t_rooms			*dst;
	int				weight;
}					t_links;

typedef struct		s_map
{
	t_list			*rooms;
	t_rooms			*start;
	t_rooms			*finish;
}					t_map;

typedef struct		s_stack
{
	t_list			*elements;
}					t_stack;

typedef struct		s_room
{
	char			*name;
	int				x;
	int				y;
}					t_room;

typedef struct		s_link
{
	char			*src;
	char			*dst;
}					t_link;

typedef struct		s_value
{
	int				ants;
	t_room			room;
	t_link			link;
}					t_value;

typedef struct		s_data
{
	int				type;
	t_value			value;
}					t_data;

typedef struct		s_input
{
	int				countl;
	t_list			*lines;
	t_list			*last;
}					t_input;

typedef struct		s_base
{
	int				ants;
	int				needf;
	int				inputf;
	int				movesf;
	t_input			input;
	t_map			map;
}					t_base;

typedef struct		s_pathes
{
	t_rooms			*origin;
	int				length;
}					t_pathes;

typedef struct		s_result
{
	int				count;
	int				*antsforpath;
	int				turns;
	t_pathes		*pathes;
}					t_result;

void				additionsplit(t_result *solve, int antsleft);
void				antsdistribute(t_result *solve, int i);
int					equalsplit(t_result *solve, int pathes);
void				goants(t_result *solve, int pathes);
int					antsmover(t_rooms **temp, t_result *best);
void				antsmovement(t_rooms **temp, int max);
void				checkas(t_data *data, char *line, int flag);
void				checklink(t_data *data, char *line);
void				checkroom(t_data *data, char *line);
void				cleanrooms(t_list *rooms);
void				findcycle(t_rooms *first, t_rooms *second);
void				checkparents(t_rooms *room);
int					findmore(t_map *map);
void				linkdistance(t_rooms *first, t_stack *stack);
int					findshortest(t_rooms *first, t_rooms *second);
void				helpuse(int flag);
void				helptimetwo(t_base *lm, char **av);
void				helptime(t_base *lm, int ac, char **av);
t_rooms				*linkpoper(t_rooms *first);
void				linkdeleter(t_rooms *first, t_rooms *second);
void				linkpusher(t_rooms *first, t_rooms *second, int weight);
t_links				*linkexclusive(t_rooms *first, t_rooms *second);
void				addlink(t_base *lm, t_data *data);
void				*poper(t_list **head);
void				pusher(t_list **head, void *data);
void				modifpath(t_rooms *first, t_rooms *temp, t_rooms *second);
void				modifmap(t_rooms *first, t_rooms *second);
void				sortpathes(t_pathes *all, int pathes);
int					findlength(t_rooms *destination);
t_pathes			*initializepath(t_rooms *start, int pathes);
void				printinput(t_input *input);
void				printresult(t_rooms **temp, int max);
void				printmoveshard(t_result *best, int ants);
void				adddata(t_data *data, char *line);
void				addline(t_base *lm, char *line);
void				readdata(t_base *lm, t_data *data);
void				initializelm(t_base *lm);
void				reader(t_base *lm);
void				readlinks(t_base *lm, t_data *data);
void				readrooms(t_base *lm, t_data *data);
void				readants(t_base *lm, t_data *data);
void				restorepath(t_rooms *first, t_rooms *temp, t_rooms *second);
void				restoremap(t_rooms *first, t_rooms *second);
t_result			*createsolve(t_rooms *start, int ants, int pathes);
void				solver(t_result **best, t_rooms *start, int ants,
	int pathes);
int					countlinks(t_rooms *src);
int					countmax(t_base *lm);
void				solvehard(t_base *lm);
void				solvedestroyer(t_result *solve);
void				solvesaver(t_result *solve);
void				printmovesnormal(t_base *lm);
void				stackdestroyer(t_stack *stack);
t_rooms				*stackpoper(t_stack *stack);
void				stackpusher(t_stack *stack, t_rooms *room);
t_stack				*createstack(void);
void				freedarray(char **input);
int					checknumber(char *str, int *coordinates);
void				addstartendr(t_base *lm, t_data *data);
t_rooms				*createroom(void);
t_rooms				*roomexclusive(t_list *rooms, char *name);
void				addroom(t_base *lm, t_data *data);
void				helpusetwo(int flag);
int					isinteger(char *str);
int					coordexclusive(t_list *rooms, int x, int y);
void				freebase(t_base *base);
void				freelinks(t_list *list);
void				freeroomname(t_list *list);
void				freedates(t_list **list);
void				presolve(t_base *lm);

#endif
