/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abertran <abertran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:18:28 by abertran          #+#    #+#             */
/*   Updated: 2022/12/02 14:07:18 by abertran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *org_str, char *bff)
{
	size_t	i;
	size_t	n;
	char	*str;

	if (!org_str)
	{
		org_str = (char *)malloc(1 * sizeof(char));
		org_str[0] = '\0';
	}
	if (!org_str || !bff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(org_str) + ft_strlen(bff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	n = 0;
	if (org_str)
		while (org_str[++i] != '\0')
			str[i] = org_str[i];
	while (bff[n] != '\0')
		str[i++] = bff[n++];
	str[ft_strlen(org_str) + ft_strlen(bff)] = '\0';
	free(org_str);
	return (str);
}

char	*ft_line(char *str)
{
	int		i;
	char	*nw;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	nw = (char *)malloc(sizeof(char) * (i + 2));
	if (!nw)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		nw[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		nw[i] = str[i];
		i++;
	}
	nw[i] = '\0';
	return (nw);
}

char	*ft_nextstr(char *str)
{
	int		i;
	int		n;
	char	*nw;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	nw = (char *) malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!nw)
		return (NULL);
	i++;
	n = 0;
	while (str[i])
		nw[n++] = str[i++];
	nw[n] = '\0';
	free(str);
	return (nw);
}
