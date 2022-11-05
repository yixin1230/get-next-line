/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/02 16:48:59 by yizhang       #+#    #+#                 */
/*   Updated: 2022/11/03 19:27:08 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list	*new_node(char *content)
{
	t_list	*node;

	node = NULL;
	if (content)
		node = malloc(sizeof(t_list));
	if (!node)
		free(node);
	node->content = content;
	node->next = NULL;
	return (node);
}

char	*get_next_line(int fd)
{
	char	file;
	t_list	*node;
	char	*oneline;
	int		i;
	int		len;

	len = 0;
	i = 1;
	file = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	//creat space for str ,use read()function read the file until we find '\n'
	if (!file)
	{
		free(file);
		return(NULL);
	}
	while (i)
	{
		i = read(fd, file, BUFFER_SIZE);
	}
	oneline = malloc((len * i + 2)*sizeof(char));
	newline_cpystr(0, oneline, i, file);
	//if we find '\n', return the line.
	node = new_node(oneline);
	return (node->content);
}
