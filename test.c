/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/03 19:26:18 by yizhang       #+#    #+#                 */
/*   Updated: 2022/11/14 11:47:12 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*s;
	char	*s2;
	char	*s3;
	char	*s4;
	char	*s5;

	fd = open("text", O_RDONLY);
	s = get_next_line(fd);
	s2 = get_next_line(fd);
	s3 = get_next_line(fd);
	s4 = get_next_line(fd);
	s5 = get_next_line(fd);
	printf("get_next_line1:%s", s);
	printf("get_next_line2:%s", s2);
	printf("get_next_line3:%s", s3);
	printf("get_next_line4:%s", s4);
	printf("get_next_line5:%s", s5);
	free(s);
	free(s2);
	free(s3);
	free(s4);
	free(s5);
	close(fd);
	//system("leaks -q a.out");
	return (0);
}
