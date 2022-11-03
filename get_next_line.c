/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/02 16:48:59 by yizhang       #+#    #+#                 */
/*   Updated: 2022/11/03 17:40:15 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>//open
#include <stdio.h>

char	*get_next_line(int fd)
{
	char	*file;
	char	*oneline;
	int		len;
	int		i;

	len = 1024;
	i = 0;
	if(fd == -1)
		return (NULL);
	file = malloc(sizeof(char) * (len + 1));
	if(!file)
	{
		free(file);
		return (NULL);
	}
	read(fd, file, len);
	while (file[i] != '\n')
	{
		i++;
	}
	oneline = malloc(sizeof(char) * (i + 2));
	if(!oneline)
	{
		free(oneline);
		return (NULL);
	}
	i = 0;
	while(file[i] != '\n')
	{
		oneline[i] = file[i];
		i++;
	}
	oneline[i] = '\n';
	oneline[i++] = '\0';
	return (oneline);
}

int main(void)
{  
	int	fd;
	char *line;

	fd = open("text",O_RDONLY);
	line = get_next_line(fd);
	if (line != NULL)
	{
		printf("%s",line);
		free(line);
	}
	close(fd);
	return (0);
}
