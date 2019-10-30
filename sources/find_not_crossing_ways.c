/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_not_crossing_ways.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 18:34:17 by jormond-          #+#    #+#             */
/*   Updated: 2019/10/21 19:03:17 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void			find_not_crossing_ways(t_lem *farm, t_room **rooms)
{
	int     i;
	int     j;
	// int		c;
	// int		k;
	// int		len[LEN];

	i = 0;
	SLINKS = rooms[0]->links + 2;
	init_stack(farm);
	LEVEL -= 1;
	start_rooms_init(farm, rooms);
	SLINKS -= 1;
	while (i++ < LEVEL)
	{
		j = 0;
		// i = 0;
		while (++j < SLINKS)
		{
			if (WAYS[j][WAYS[j][LEVEL]] != KILL
				&& WAYS[j][WAYS[j][LEVEL]] != farm->end->index)
			{
				how_many_forks(farm, rooms, j);
				what_we_should_do(farm, rooms, j);
			}
			// index_modifier(farm, rooms, j, &i);
		}
	}
	// printf("%d - fork\n", rooms[WAYS[1][2]]->fork);
	// i = 0;
	// while (++i < SLINKS)
	// {
	// 	j = -1;
	// 	while (++j < LEVEL)
	// 	{
	// 		if (j != (LEVEL - 1))
	// 			printf("%d\t", WAYS[i][j]);
	// 		else if (j == (LEVEL - 1))
	// 			printf("\033[1;32m%d\033[0m\n", WAYS[i][j]);
	// 	}
	// 	printf("\n");
	// }
	// j = 0;
	// while (++j < SLINKS)
	// {
	// 	i = -1;
	// 	if (WAYS[j][WAYS[j][LEVEL]] == farm->end->index)
	// 	{
	// 		while (++i <= LEVEL)
	// 		{
	// 			// k = -1;
	// 			// len[k]
	// 			if (i == 0)
	// 				printf("\033[1;34m%d\033[0m\t", WAYS[j][i]);
	// 			else if (i != LEVEL)
	// 				printf("%d\t", WAYS[j][i]);
	// 			else if (i == LEVEL)
	// 				printf("\033[1;32m%d\033[0m", WAYS[j][i]);
	// 		}
	// 		printf("\n\n");
	// 	}
	// }
	// printf("\n");
	// printf("%d LEN\n", LEN);
	// printf("%d end\n", farm->end->index);
	// c = -1;
	// k = 0;
    // while (++c < farm->start->links)
    // {
    //     printf("\t\e[1;32m%d\e[0m\t\t", c);
    //     j = 0;
    //     while (++j <= SLINKS)
    //     {
    //         if (WAYS[c][j] != -1 && WAYS[c][j] != -1)
    //         {
    //             len[++k] = WAYS[c][j];
    //             i = -1;
    //             while (++i < k)
    //             {
    //                 if (len[i] == WAYS[c][j])
    //                 {
    //                     printf("\e[1;34m%d\e[0m\t", WAYS[c][j]);
    //                     break ;
    //                 }
    //             }
    //             printf("%d\t", WAYS[c][j]);
    //         }
    //     }
    //     printf ("\e[1;31m%d\e[0m\n", WAYS[c][LEVEL + 199]);
    // }
}

void			init_stack(t_lem *farm)
{
	int		i;
	int		j;
	// int		k;

	i = -1;
	LEVEL += 20;
	if(!(WAYS = (int **)malloc(sizeof(int *) * SLINKS)))
		error_output();
	while (++i < SLINKS)
	{
		if (!(WAYS[i] = (int *)malloc(sizeof(int) * LEVEL)))
			error_output();
		j = -1;
		while (++j < LEVEL)
			WAYS[i][j] = 0;
	}
}

void			start_rooms_init(t_lem *farm, t_room **rooms)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	while (++i < LEN)
	{
		if (MAP[0][i] == 1)
		{
			WAYS[j][0] = j;
			WAYS[j][1] = rooms[i]->index;
			rooms[i]->stop = j;
			WAYS[j++][LEVEL] = 1;
		}
	}
}

void			how_many_forks(t_lem *farm, t_room **rooms, int j)
{
	int		k;
	int		i;

	k = WAYS[j][LEVEL];
	i = 0;
	if (k == 1 && rooms[WAYS[j][k]]->links == 2)
		rooms[WAYS[j][k]]->fork = 1;
	if (rooms[WAYS[j][k]]->links > 2)
		return ;
	else if (rooms[WAYS[j][k]]->links == 2 && rooms[WAYS[j][k - 1]]->fork == 1)
		rooms[WAYS[j][k]]->fork = 1;
}

// void			index_modifier(t_lem *farm, t_room **rooms, int j, int *i)
// {
// 	if (WAYS[j][WAYS[j][LEVEL]] != KILL
// 		&& WAYS[j][WAYS[j][LEVEL]] != farm->end->index)
// 		(*i) += 1;
// }

/**************************************************/
/**************************************************/
/**************************************************/

// void			find_not_crossing_ways(t_lem *farm, t_room **rooms)
// {
// 	int		i;
// 	int		k;

// 	init_stack(farm);
// 	start_rooms_init(farm, rooms);
// 	lets_begin(farm, rooms);
// 	i = 0;

// }

// void			lets_begin(t_lem *farm, t_room **rooms)
// {
// 	int		i;
// 	int		j;
// 	int		k;

// 	j = 0;
// 	while (++j < LEVEL)
// 	{
// 		i = 0;
// 		while (++i <= SLINKS)
// 		{
// 			choose_your_way(farm, rooms, i);
// 			// printf("%d\n", j);
// 		}
// 		// printf("\n\n");
// 	}
// }

// void			choose_your_way(t_lem *farm, t_room **rooms, int i)
// {
// 	int		j;
// 	int		k;

// 	k = WAYS[i][LEVEL];
// 	j = 0;
// 	if (rooms[WAYS[i][k]]->name == farm->end->name)
// 		return ;
// 	while (++j <= LEN)
// 	{
// 		if (MAP[WAYS[i][k]][j] == 1)
// 		{
// 			if (rooms[j]->stop != i)
// 			{
// 				what_we_should_do(farm, rooms, i, j);
// 			}
// 		}
// 	}
// 	k = WAYS[i][LEVEL];
// 	if (rooms[WAYS[i][k]]->index != farm->end->index)
// 		rooms[WAYS[i][k]]->stop = i;
// 	WAYS[i][LEVEL] = k + 1;
// 	// printf("%d\n", WAYS[i][LEVEL]);
// 	// k = -1;
// 	// printf("%d\n", i);
// 	// while (++k <= LEVEL)
// 	// 	printf("%d ", WAYS[i][k]);
// 	// printf("\n");
	// k = -1;
	// while (++k <= LEN)
	// 	printf("%d) %s = room's name\n", k, rooms[k]->name);
	// k = -1;
	// printf("%d\n", i);
	// while (++k <= LEVEL)
	// 	printf("%d ", WAYS[i][k]);
	// printf("\n");
	// printf("\n");
// }
