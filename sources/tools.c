/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:07:51 by jormond-          #+#    #+#             */
/*   Updated: 2019/10/17 17:01:56 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int         words_counter(char *line)
{
	int     res;
	int     i;

	i = -1;
	res = 1;
	while (line[++i])
		if (line[i] != ' ' && line[i + 1] == ' ')
			res++;
	return (res);
}

int         count_rooms(char *buf)
{
	int     res;
	int     i;

	i = -1;
	res = 0;
	while (buf[++i])
	{
		if (buf[i] == '\n')
			res++;
	}
	return (res + 2);
}

void		split_free(char **tmp)
{
	int		i;

	i = -1;
	while (tmp[++i])
		free(tmp[i]);
	free(tmp);
}

int			count_links(int *arr)
{
	int		i;

	i = 0;
	while (++i)
		if (arr[i] == 0)
			break ;
	return (i);
}

void		clear_the_way(t_lem *farm, t_room **rooms, int j, int k)
{
	int		l;

	l = k + 1;
	while (WAYS[j][l] != 0 && l < LEVEL)
	{
		// printf("%d stop\n", WAYS[j][l]);
		rooms[WAYS[j][l]]->stop = 0;
		WAYS[j][l] = 0;
		l++;
	}
}
