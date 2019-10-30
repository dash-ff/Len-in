/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 15:44:44 by jormond-          #+#    #+#             */
/*   Updated: 2019/10/20 15:02:07 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		start_room(char *line, t_lem **farm)
{
	char	**tmp;

	(*farm)->s = 2;
	tmp = ft_strsplit(line, ' ');
	if (!((*farm)->start = (t_room *)malloc(sizeof(t_room))))
		error_output();
	(*farm)->start->name = ft_strdup(tmp[0]);
	(*farm)->start->x = ft_atoi(tmp[1]);
	(*farm)->start->y = ft_atoi(tmp[2]);
	(*farm)->start->index = 0;
	(*farm)->start->links = 0;
	(*farm)->start->level = 0;
	(*farm)->start->back_level = 0;
	(*farm)->start->stop = 0;
	(*farm)->start->fork = 0;
	split_free(tmp);
}

void		end_room(char *line, t_lem **farm)
{
	char	**tmp;

	(*farm)->e = 2;
	tmp = ft_strsplit(line, ' ');
	if (!((*farm)->end = (t_room *)malloc(sizeof(t_room))))
		error_output();
	(*farm)->end->name = ft_strdup(tmp[0]);
	(*farm)->end->x = ft_atoi(tmp[1]);
	(*farm)->end->y = ft_atoi(tmp[2]);
	(*farm)->end->links = 0;
	(*farm)->end->level = 0;
	(*farm)->end->back_level = 0;
	(*farm)->end->stop = 0;
	(*farm)->start->fork = 0;
	split_free(tmp);
}

void        valid_x(char *tmp)
{
	int		res;

	if (ft_atoi(tmp) != ft_atol(tmp))
		error_output();
	res = ft_atoi(tmp);
}

void        valid_y(char *tmp)
{
	int		i;
	int		res;

	i = 0;
	if (ft_atoi(tmp) != ft_atol(tmp))
		error_output();
	res = ft_atoi(tmp);
}

void			fill_rooms(t_room *room, char **tmp, int i)
{
	room->name = ft_strdup(tmp[0]);
	room->x = ft_atoi(tmp[1]);
	room->y = ft_atoi(tmp[2]);
	room->level = 0;
	room->back_level = 0;
	room->index = i;
	room->book = 0;
	room->links = 0;
	room->stop = 0;
	room->fork = 0;
}