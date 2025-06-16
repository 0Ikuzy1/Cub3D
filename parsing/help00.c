/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 03:04:40 by iqattami          #+#    #+#             */
/*   Updated: 2025/06/16 15:57:35 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	init_var(t_map *data)
{
	data->count = 0;
	data->i = 0;
	data->j = 0;
}

int	end_of_read_lines(char *line, char **t)
{
	free(line);
	t[0] = NULL;
	return (1);
}

char	*helper31(char *line, int k)
{
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	return (ft_strdup(&line[k]));
}

void	free_map_data(t_map *data)
{
	if (!data)
		return ;
	if (data->map)
		free_tab(data->map);
	free(data);
}
