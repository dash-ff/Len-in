/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   warriors_way.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:13:25 by jormond-          #+#    #+#             */
/*   Updated: 2019/10/21 13:53:41 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		warriors_way(t_lem *farm, t_room **rooms, int *arr, int j)
{
	int		i;
	int		k;

	i = 0;
	k = WAYS[j][LEVEL] + 1;
	if (this_way(farm, rooms, j, k) == OK)
		return ;
	while (++i < LEVEL && arr[i] != 0)
		if (this_two_ways(farm, rooms, arr[i], j) == OK)
			return ;
	WAYS[j][LEVEL] = KILL;
	// k = WAYS[j][LEVEL] + 1;
	// printf("%d way\n", WAYS[j][LEVEL]);
	// printf("%d wayway\n\n", WAYS[j][WAYS[j][LEVEL]]);
	// if (i < LEVEL)
	// {
	// 	rooms[WAYS[j][k - 1]]->stop = j;
	// }
	// if (i == LEVEL)
	// 	WAYS[j][LEVEL] = KILL;
	// printf("%d \n", WAYS[j][LEVEL]);
}

int			this_two_ways(t_lem *farm, t_room **rooms, int arr, int j)
{
	int		j1;
	int		k1;
	int		k;

	j1 = rooms[arr]->stop;
	k1 = 1;
	k = WAYS[j][LEVEL];
	while (k1 < LEVEL && rooms[WAYS[j1][k1]]->index != rooms[arr]->index)
		k1++;
	while (--k1 > 0)
	{
		if (find_free_ways(farm, rooms, j1, k1) == OK)
		{
			WAYS[j][LEVEL] = k + 1;
			WAYS[j][k + 1] = rooms[arr]->index;
			clear_the_way(farm, rooms, j1, WAYS[j1][LEVEL]);
			return (OK);
		}
	}
	return (ERROR);
}

int			find_free_ways(t_lem *farm, t_room **rooms, int j, int k)
{
	int		arr[LEVEL];
	int		free;
	int		num;
	int		i;

	i = 0;
	num = 0;
	free = 0;
	ft_bzero(arr, (LEVEL * 4));
	while (++i < LEN)
		if (MAP[WAYS[j][k]][i] == 1 && rooms[i]->stop != j)
			fill_array(rooms[i], arr, ++num, &free);
	if (free == 0)
		return (ERROR);
	WAYS[j][LEVEL] = k;
	if (num == 1 && free == 1)
		one_free_way(farm, rooms, arr, j);
	else if (num > 1 && free == 1)
		which_one_free_way(farm, rooms, arr, j);
	else if (num > 1 && free > 1)
		to_much_free_ways(farm, rooms, arr, j);
	return (OK);
}

int			this_way(t_lem *farm, t_room **rooms, int j, int k)
{
	while (--k > 0)
	{
		if (find_free_ways(farm, rooms, j, k) == OK)
		{
			clear_the_way(farm, rooms, j, WAYS[j][LEVEL]);
			return (OK);
		}
	}
	return (ERROR);
}

// void		not_any_way(t_lem *farm, t_room **rooms, int *arr, int j)
// {
// 	int		i;
// 	int		k;
// 	int		len;

	
// 	len = count_links(arr);
// 	k = WAYS[j][LEVEL];
// 	i = 0;
// 	while (++i < len)
// 		compare_free_ways(rooms, WAYS[j][k], &(WAYS[j][k + 1]), arr[i]);
// 	if (rooms[WAYS[j][k]]->index != farm->end->index)
// 		rooms[WAYS[j][k + 1]]->stop = j;
// 	WAYS[j][LEVEL] = k + 1;
// }
