/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_ways.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:46:44 by jormond-          #+#    #+#             */
/*   Updated: 2019/10/21 13:51:02 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void            what_we_should_do(t_lem *farm, t_room **rooms, int j)
{
	int		arr[LEVEL + 1];
	int		free;
	int		k;
	int		i;

	i = 0;
	k = 0;
	free = 0;
	ft_bzero(arr, (LEVEL * 4));
	if (rooms[WAYS[j][WAYS[j][LEVEL]]]->links > 2)
		cut_equal_ways(farm, rooms, j);
	while (++i < LEN)
		if (MAP[WAYS[j][WAYS[j][LEVEL]]][i] == 1 && rooms[i]->stop != j)
			fill_array(rooms[i], arr, ++k, &free);
	if (k == 1 && free == 1)
		one_free_way(farm, rooms, arr, j);
	else if (k > 1 && free == 1)
		which_one_free_way(farm, rooms, arr, j);
	else if (k > 1 && free > 1)
		to_much_free_ways(farm, rooms, arr, j);
	else if (k >= 1 && free <= 0)
		warriors_way(farm, rooms, arr, j);
}

void			fill_array(t_room *room, int *arr, int k, int *free)
{
	if (room->stop == 0)
	{
		arr[k] = room->index;
		*free += 1;
	}
	else
		arr[k] = room->index;
}

void			one_free_way(t_lem *farm, t_room **rooms, int *arr, int i)
{
	int		l;

	l = WAYS[i][LEVEL] + 1;
	WAYS[i][l] = rooms[arr[1]]->index;
	if (rooms[arr[1]]->index != farm->end->index)
		rooms[arr[1]]->stop = i;
	WAYS[i][LEVEL] = l;
}

void			which_one_free_way(t_lem *farm, t_room **rooms, int *arr, int j)
{
	int		i;
	int		k;

	i = 0;
	k = WAYS[j][LEVEL] + 1;
	while (++i < LEVEL)
		if (rooms[arr[i]]->stop == 0)
			break ;
	WAYS[j][k] = arr[i];
	if (rooms[arr[i]]->index != farm->end->index)
		rooms[arr[i]]->stop = j;
	WAYS[j][LEVEL] = k;
}

void			to_much_free_ways(t_lem *farm, t_room **rooms, int *arr, int j)
{
	int		i;
	int		k;
	int		len;

	
	len = count_links(arr);
	k = WAYS[j][LEVEL];
	i = 0;
	while (++i < len)
		if (rooms[arr[i]]->stop == 0)
			compare_free_ways(rooms, WAYS[j][k], &(WAYS[j][k + 1]), arr[i]);
	if (rooms[WAYS[j][k]]->index != farm->end->index)
		rooms[WAYS[j][k + 1]]->stop = j;
	WAYS[j][LEVEL] = k + 1;
}
