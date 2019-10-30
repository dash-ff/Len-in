/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brickon- <brickon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:10:42 by brickon-          #+#    #+#             */
/*   Updated: 2019/10/29 13:15:37 by brickon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void            parce_arg(t_lem *farm, char *av)
{
    if (av[0] == '-')
	{
		if (ft_strchr(av, 'l'))
            farm->l = 1;
		if (ft_strchr(av, 's'))
            farm->steps = 1;
		else if (ft_strchr(av, 'w'))
            farm->w = 1;
        if (ft_strchr(av, 'm'))
            farm->music = 1;
        if (ft_strchr(av, 'v'))
            farm->vizu = 1;
	}
}