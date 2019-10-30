/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   occupied_rooms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:04:25 by jormond-          #+#    #+#             */
/*   Updated: 2019/10/20 20:21:31 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

// void			scouting(t_lem *farm, t_room **rooms, int i)
// {
// 	int		j;

// 	j = 0;
// 	while (WAYS[i][++j] != farm->end->index)
// 	{
// 		// if (rooms[WAYS[i][j]]->links == 2)
// 			this_way(farm, rooms, i, j);
// 	}
// }

// void			this_way(t_lem *farm, t_room **rooms, int i, int j)
// {
// 	int		k;

// 	k = 0;
// 	while (++k < LEN)
// 	{
// 		if (MAP[WAYS[i][j]][k] == 1 && rooms[k]->stop != i)
// 		{
// 			if (rooms[k]->level > rooms[WAYS[i][j]]->level)
// 			{
// 				printf("%s \n", rooms[k]->name);
// 				one_free_way(farm, rooms, k, i);
// 				return ;
// 			}
// 			else if (rooms[k]->back_level > rooms[WAYS[i][j]]->back_level)
// 			{
// 				printf("%s !\n", rooms[k]->name);
// 				one_free_way(farm, rooms, k, i);
// 				return ;
// 			}
// 		}
// 	}
// }


// void			is_it_deadlock(t_lem *farm, t_room **rooms, int arr, int j)
// {
// 	int		k;
// 	int		j1;
// 	int		k1;

// 	k = WAYS[j][LEVEL] + 1;
// 	j1 = rooms[arr]->stop;
// 	k1 = WAYS[j1][LEVEL];
// 	while (--k > 0 && rooms[WAYS[j][k]]->fork != 1)
// 		if (find_free_room(farm, rooms, j, k) == OK)
// 			break ;
// 	while (k1 > 0 && rooms[WAYS[j1][k1]]->index != rooms[arr]->index)
// 		k1--;	
// 	while (--k1 > 0 && rooms[WAYS[j1][k1]]->fork != 1)
// 	{
// 		printf("%s - name1 rererere\n", rooms[WAYS[j1][k1]]->name);
// 		printf("%d - fork forerere\n", rooms[WAYS[j1][k1]]->fork);
// 		if (find_free_room(farm, rooms, j1, k1) == OK)
// 		{
// 			break ;
// 		}
// 	}
// 	printf("%d - k , %d - k1\n\n", k, k1);
// 	if ((rooms[WAYS[j][k]]->fork == 1 || k == 0) &&
// 		(rooms[WAYS[j1][k1]]->fork == 1 || k1 == 0))
// 		WAYS[j][LEVEL] = KILL;
// 	else if (rooms[WAYS[j][k]]->fork == 0)
// 		turn_else_way(farm, rooms, j, k + 1);
// 	else if (rooms[WAYS[j1][k1]]->fork == 0)
// 		turn_else_way(farm, rooms, j1, k1 + 1);
// }

int				find_free_room(t_lem *farm, t_room **rooms, int j, int k)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	if (rooms[WAYS[j][k]]->links > 2)
		while (++i < LEN)
			if (MAP[WAYS[j][k]][i] == 1)
				if (rooms[i]->stop == 0)
					res++;
	return (res);
}

void			turn_else_way(t_lem *farm, t_room **rooms, int j, int k)
{
	int		i;

	i = 0;
	// printf("%d way\n", WAYS[j][k]);
	// printf("%d kkk\n", k);
	while (++i < LEN)
	{
		if (MAP[WAYS[j][k]][i] == 1)
		{
			if (rooms[i]->stop == 0)
			{
				WAYS[j][k + 1] = rooms[i]->index;
				WAYS[j][LEVEL] = k + 1;
				rooms[i]->stop = j;
				// printf("%d way\n", WAYS[j][LEVEL]);
				// printf("%d sss\n", rooms[i]->index);
				break ;
			}
		}
	}
	// printf("%d i \n", i);
	clear_the_way(farm, rooms, j, WAYS[j][LEVEL]);
}

void			compare_free_ways(t_room **rooms, int way, int *nextway, int i)
{
	// printf("%d - rooms index\n", rooms[way]->index);
	// printf("%d - rooms index\n", rooms[(*nextway)]->index);
	// printf("%d - rooms index\n", rooms[(*nextway)]->level);
	// printf("%d - rooms index\n", rooms[(*nextway)]->back_level);
	// printf("%d - rooms i\n", rooms[i]->index);
	// printf("%d - rooms i\n", rooms[i]->level);
	// printf("%d - rooms i\n", rooms[i]->back_level);
	if ((*nextway) == 0)
	{
		if (rooms[i]->level > rooms[way]->level)
			(*nextway) = rooms[i]->index;
		else if (rooms[i]->level <= rooms[way]->level)
		{
			if (rooms[i]->back_level >= rooms[way]->back_level)
				(*nextway) = rooms[i]->index;
			// printf("!\n");
		}
	}
	else
	{
		if (rooms[i]->level > rooms[(*nextway)]->level)
			(*nextway) = rooms[i]->index;
		else 
		{
			if (rooms[i]->back_level >= rooms[(*nextway)]->back_level)
				(*nextway) = rooms[i]->index;
				// printf("!!\n");
		}
	}
	// printf("%d nextway\n", (*nextway));
}

void			cut_equal_ways(t_lem *farm, t_room **rooms, int j)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (++i < LEN)
	{
		if (MAP[WAYS[j][WAYS[j][LEVEL]]][i] == 1 && rooms[i]->stop != j)
		{
			if (rooms[i]->level == rooms[WAYS[j][WAYS[j][LEVEL]]]->level)
			{
				if (rooms[i]->back_level
					== rooms[WAYS[j][WAYS[j][LEVEL]]]->back_level)
				{
					MAP[WAYS[j][WAYS[j][LEVEL]]][i] = 0;
					MAP[i][WAYS[j][WAYS[j][LEVEL]]] = 0;
					rooms[WAYS[j][WAYS[j][LEVEL]]]->links--;
					rooms[i]->links--;
				}	
			}
		}
	}
}