/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 18:35:58 by jormond-          #+#    #+#             */
/*   Updated: 2019/10/12 14:57:12 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		valid_rooms(char *line, t_lem *farm, char **buf)
{
	if (line[0] == '#' || (line[0] && line[1] == '#'))
	{
		if (!ft_strcmp(line, "##start\n"))
			valid_start(farm);
		else if (!ft_strcmp(line, "##end\n"))
			valid_end(farm);
		else
			return ;
	}
	else
	{
		is_valid_line(line);
		save_rooms(line, &farm, buf);
		if (farm->s == 1 || farm->e == 1)
			error_output();
	}
	
}

void		valid_start(t_lem *farm)
{
	if (farm->s == 0 && (farm->e == 0 || farm->e == 2))
		farm->s = 1;
	else
		error_output();
}

void		valid_end(t_lem *farm)
{
	if (farm->e == 0 && (farm->s == 0 || farm->s == 2))
		farm->e = 1;
	else
		error_output();
}

void		save_rooms(char *line, t_lem **farm, char **buf)
{
	int		i;

	i = -1;
	if ((*farm)->s == 1)
	{
		start_room(line, farm);
		return ;
	}
	if ((*farm)->e == 1)
	{
		end_room(line, farm);
		return ;
	}
	!(*buf) ? (*buf) = ft_strdup(line) : ft_join_free(buf, line);
}

void		is_valid_line(char *line)
{
	char	**tmp;
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (line[j] != '\n')
		j++;
	if (line[j - 1] == ' ')
		error_output();
	tmp = ft_strsplit(line, ' ');
	valid_x(tmp[i++]);
	valid_y(tmp[i]);
	split_free(tmp);
}