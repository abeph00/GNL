/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abertran <abertran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:18:42 by abertran          #+#    #+#             */
/*   Updated: 2022/12/13 15:47:46 by abertran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *str)
{
	char	*bff;
	int		bytes;

	bff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!bff)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(str, '\n') && bytes != 0)
	{
		bytes = read(fd, bff, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(bff);
			free(str);
			return (NULL);
		}
		bff[bytes] = '\0';
		str = ft_strjoin(str, bff);
	}
	free(bff);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*ln;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = ft_read(fd, str);
	if (!str)
		return (0);
	ln = ft_line(str);
	str = ft_nextstr(str);
	return (ln);
}

/*int	main(void)
{
	int fd;
    char *tab;
    fd = open("test.txt", O_RDONLY);
    tab = get_next_line(fd);
    printf("%s", tab);
    free(tab);
    tab = get_next_line(fd);
    printf("%s", tab);
    tab = get_next_line(fd);
    printf("%s", tab);
    tab = get_next_line(fd);
    printf("%s", tab);
    close(fd);
	return (0);
}*/