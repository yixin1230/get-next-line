/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/03 19:26:18 by yizhang       #+#    #+#                 */
/*   Updated: 2022/11/07 16:48:40 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>//open
#include <stdio.h>

int main(void)
{  
	int	fd;

	fd = open("text",O_RDONLY);
	printf("1:%s\n",get_next_line(fd));
	printf("2:%s\n",get_next_line(fd));
	printf("3:%s\n",get_next_line(fd));
	close(fd);
	return (0);
}
