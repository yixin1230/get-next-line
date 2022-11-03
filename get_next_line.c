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

	node = malloc(sizeof(t_list));
	node->content = content;
	node->next = NULL;
	return (node);
}

char	*get_next_line(int fd)
{
	char	*file;
	char	*oneline;
	static t_list *node;
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
	node = new_node(oneline);
	return (node->content);
}
