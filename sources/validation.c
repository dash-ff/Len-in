/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 18:12:32 by jormond-          #+#    #+#             */
/*   Updated: 2019/10/17 16:56:24 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		validation(char *line, t_lem *farm, char **buf, t_room ***rooms)
{
	first_valid(line, farm);
	if (ANTS == '0' && ROOMS == '1')
		line_identificator(line, farm);
	if (line)
	{
		if (ANTS == '1')
			valid_ants(line, farm);
		else if (ROOMS == '1')
			valid_rooms(line, farm, buf);
		else if (LINKS == '1')
		{
			if (ROOMS != '2')
				parse_and_create(farm, *buf, rooms);
			valid_links(line, farm, rooms);
		}
	}
	else
		error_output();
}

void		valid_ants(char *line, t_lem *farm)
{
	int		i;

	i = -1;
	if (line[0] == '#' || (line[0] == '#' && line[1] == '#'))
		return ;
	if (ft_strchr("123456789", line[0]))
	{
		while (line[++i] != '\n')
			if (!ft_isdigit(line[i]))
				error_output();
		farm->ants = ft_atoi(line);
		ANTS = '0';
	}
	else
		error_output();
}

void		line_identificator(char *line, t_lem *farm)
{
	int		words;
	int		i;

	i = -1;
	words = words_counter(line);
	if (line[0] == '#' || (line[0] == '#' && line[1] == '#'))
		return ;
	if (words > 1)
		while (line[++i] != ' ')
			if (is_hyphen(line[i]))
				error_output();
	if (ROOMS != '2')
		if (ROOMS == '0')
			error_output();
	if ((words > 3 || words == 2) && ROOMS == '1')
		error_output();
	if (words == 1 && ROOMS == '1' && ANTS == '0')
		ROOMS = '0';
}

void		first_valid(char *line, t_lem *farm)
{
	if (line[0] == 'L' || line[0] == ' ' || line[0] == '\n' ||
		(!ft_strcmp(line, "##start\n") && (ANTS == '1' || ROOMS == '0')) ||
		(!ft_strcmp(line, "##end\n") && (ANTS == '1' || ROOMS == '0')))
		error_output();
	// if (ANTS == '0' && ROOMS == '1')
	// 	line_identificator(line, farm);
}
