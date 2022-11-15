/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/03 19:26:18 by yizhang       #+#    #+#                 */
/*   Updated: 2022/11/15 18:49:39 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;

	fd = open("text", O_RDONLY);
	printf("get_next_line1:%s", get_next_line(fd));
	printf("get_next_line2:%s", get_next_line(fd));
	printf("get_next_line3:%s", get_next_line(fd));
	printf("get_next_line4:%s", get_next_line(fd));
	printf("get_next_line5:%s", get_next_line(fd));
	system("leaks -q a.out");
	return (0);
}
