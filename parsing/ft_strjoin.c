/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 08:50:51 by iqattami          #+#    #+#             */
/*   Updated: 2025/06/13 20:26:07 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*ft_strduup(const char *s)
{
	char	*p;
	int		i;

	i = 0;
	while (s[i])
		i++;
	p = malloc(sizeof(char) * (i + 1));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = 0;
	return (p);
}

static char	*ft_copy(char *m, char const *s1, char const *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		m[i] = s1[i];
		i++;
	}
	while (s2[j])
		m[i++] = s2[j++];
	m[i] = '\0';
	return (m);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s;
	char	*m;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (ft_strduup(s2));
	if (!s2)
		return (ft_strduup(s1));
	s = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	m = malloc(sizeof(char) * s);
	if (m == NULL)
		return (NULL);
	m = ft_copy(m, s1, s2);
	return (m);
}
