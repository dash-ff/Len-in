/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 19:48:19 by jormond-          #+#    #+#             */
/*   Updated: 2019/10/18 16:07:53 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void        valid_links(char *line, t_lem *farm, t_room ***rooms)
{
	if (line[0] == '#')
		return ;
	if (ft_strchr(line, '-') != ft_strrchr(line, '-')
		|| words_counter(line) != 1)
		error_output();
	else
		parse_links(line, farm, rooms);
}

void		parse_links(char *line, t_lem *farm, t_room ***rooms)
{
	char	**tmp;
	int		i;
	int		j;

	*(ft_strchr(line, '\n')) = '\0';
	tmp = ft_strsplit(line, '-');
	valid_name(farm, rooms, tmp[0]);
	valid_name(farm, rooms, tmp[1]);
	i = init_index(farm, rooms, tmp[0]);
	j = init_index(farm, rooms, tmp[1]);
	farm->map[i][j] = 1;
	farm->map[j][i] = 1;
	(*rooms)[i]->links++;
	(*rooms)[j]->links++;
	split_free(tmp);
}

void		valid_name(t_lem *farm, t_room ***rooms, char *tmp)
{
	int		i;

	i = -1;
	while (++i <= farm->c_rooms)
		if (!ft_strcmp((*rooms)[i]->name, tmp))
			return ;
	error_output();
}

int			init_index(t_lem *farm, t_room ***rooms, char *tmp)
{
	int		i;

	i = -1;
	while (++i <= farm->c_rooms)
		if (!ft_strcmp((*rooms)[i]->name, tmp))
			break;
	return (i);
}
