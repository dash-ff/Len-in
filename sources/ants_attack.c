/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_attack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brickon- <brickon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:06:39 by jormond-          #+#    #+#             */
/*   Updated: 2019/10/23 01:04:24 by brickon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void            ants_attack(t_lem *farm, t_room **rooms, t_ant ***ants, t_viz *vv)
{
	int		arr[SLINKS];
	int		i;
	int		give_way;

	i = 0;
	give_way = 0;
	farm->ant_output = ft_strnew(0);
	ft_bzero(arr, (SLINKS * 4));
	while (++i < SLINKS)
		arr[i] = WAYS[i][LEVEL];
	init_ants(farm, ants, arr);
	attack_order(farm, rooms, ants, vv);
}

void			init_ants(t_lem *farm, t_ant ***ants, int *arr)
{
	int		i;

	i = -1;
	if (!((*ants) = (t_ant **)malloc(sizeof(t_ant *) * farm->ants)))
		exit(0);
	while (++i < farm->ants)
		if (!((*ants)[i] = (t_ant *)malloc(sizeof(t_ant))))
			exit(0);
	i = -1;
	while (++i < farm->ants)
		fill_ants(farm, ants, i, arr);
}

void			fill_ants(t_lem *farm, t_ant ***ants, int i, int *arr)
{
	(*ants)[i]->num = i + 1;
	(*ants)[i]->i = 0;
	(*ants)[i]->way = give_way(farm, arr);
	(*ants)[i]->marching = 0;
	(*ants)[i]->start_w = 0.0;
	(*ants)[i]->start_h = 0.0;
	(*ants)[i]->end_w = 0.0;
	(*ants)[i]->end_h = 0.0;
	// printf("%d way\n", (*ants)[i]->way[0]);
	// printf("%d i\n", (*ants)[i]->i);
	// printf("%d num\n", (*ants)[i]->num);
	// i = 0;
	// while (++i < SLINKS)
	// 	printf("%d\t", arr[i]);
	// printf("\n\n");
}

int				*give_way(t_lem *farm, int *arr)
{
	int		i;
	int		len;
	int		res;

	i = 0;
	len = 1000;
	res = 0;
	while (++i < SLINKS && arr[i] != 0)
	{
		if (arr[i] < len)
		{
			res = i;
			len = arr[i];
		}
	}
	arr[res] += 1;
	return (WAYS[res]);
}
