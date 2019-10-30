/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 14:44:17 by jormond-          #+#    #+#             */
/*   Updated: 2019/10/21 18:54:05 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		parse_and_create(t_lem *farm, char *buf, t_room ***rooms)
{
	if (farm->s != 2 && farm->e != 2)
		error_output();
	LEN = count_rooms(buf);
	parse_rooms(farm, buf, rooms);
	create_map(farm);
}

void		parse_rooms(t_lem *farm, char *buf, t_room ***rooms)
{
	char	**tmp;
	int     i;
	int		len;

	i = -1;
	len = LEN - 1;
	tmp = ft_strsplit(buf, '\n');
	if (ROOMS == '0')
	{
		if (!((*rooms) = (t_room **)malloc(sizeof(t_room *) * LEN)))
			exit(0);
		while(++i < LEN)
			if (!((*rooms)[i] = (t_room *)malloc(sizeof(t_room))))
				exit(0);
		i = 0;
		start_init(farm, rooms);
		while (++i < len)
			check_and_fill(rooms, tmp[i - 1], i);
		farm->end->index = len;
		end_init(farm, rooms, len);
		ROOMS = '2';
	}
	split_free(tmp);
}

void        create_map(t_lem *farm)
{
	int		i;
	int		j;

	i = -1;
	if (!(MAP = (int **)malloc(sizeof(int *) * LEN)))
		exit(0);
	while (++i < LEN)
	{
		if (!(MAP[i] = (int *)malloc(sizeof(int) * LEN)))
			exit(0);
		j = -1;
		while (++j < LEN)
			MAP[i][j] = 0;
	}
}

void		check_and_fill(t_room ***rooms, char *tmp, int i)
{
	char		**tmp1;
    int			c;
    int			x;
    int			y;

    c = -1;
	tmp1 = ft_strsplit(tmp, ' ');
    x = ft_atoi(tmp1[1]);
    y = ft_atoi(tmp1[2]);
	fill_rooms((*rooms)[i], tmp1, i);
    while (++c < i)
        if (tmp1[0] == (*rooms)[c]->name
			|| (x == (*rooms)[c]->x && y == (*rooms)[c]->y))
            error_output();
	split_free(tmp1);
}

void		start_init(t_lem *farm, t_room ***rooms)
{
	(*rooms)[0]->name = ft_strdup(farm->start->name);
	(*rooms)[0]->x = farm->start->x;
	(*rooms)[0]->y = farm->start->y;
	(*rooms)[0]->level = 0;
	(*rooms)[0]->back_level = 0;
	(*rooms)[0]->index = 0;
	(*rooms)[0]->book = 0;
	(*rooms)[0]->links = 0;
}

void		end_init(t_lem *farm, t_room ***rooms, int len)
{
	int		i;

	i = -1;
	(*rooms)[len]->name = ft_strdup(farm->end->name);
	(*rooms)[len]->x = farm->end->x;
	(*rooms)[len]->y = farm->end->y;
	(*rooms)[len]->level = 0;
	(*rooms)[len]->back_level	= 0;
	(*rooms)[len]->index = len;
	(*rooms)[len]->book = 0;
	(*rooms)[len]->links = 0;
	while (++i < len)
		if ((*rooms)[len]->name == (*rooms)[i]->name || ((*rooms)[len]->x
			== (*rooms)[i]->x && (*rooms)[len]->y == (*rooms)[i]->y))
            error_output();
}
