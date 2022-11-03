/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/03 19:26:18 by yizhang       #+#    #+#                 */
/*   Updated: 2022/11/03 19:26:52 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>//open
#include <stdio.h>

int main(void)
{  
	int	fd;
	char *line;

	fd = open("text",O_RDONLY);
	line = get_next_line(fd);
	if (line != NULL)
	{
		printf("%s",line);
		printf("%s",line);
		free(line);
	}
	close(fd);
	return (0);
}
