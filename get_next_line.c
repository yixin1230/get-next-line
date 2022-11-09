/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/02 16:48:59 by yizhang       #+#    #+#                 */
/*   Updated: 2022/11/08 14:40:36 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

static char	*find_nl(int fd,char **store_str)
{
	int		i;
	char	*buff;
	
	i = 1;
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return(NULL);
	while (i)
	{
		i = read(fd, buff, BUFFER_SIZE);
		buff[i] = '\0';
		if (i < 0)
			return (NULL);
		if (i == 0)
			break;
		if(!*store_str)
			*store_str = ft_strdup_gnl(buff);
		else
			*store_str = ft_strjoin_gnl(*store_str, buff);
		if (ft_strchr_gnl(*store_str, '\n') != 0)
		{
			printf("store_str:%s\n",*store_str);
			return (*store_str);	
		}
	}
	return (*store_str);
}

static char	*store_remaining(char **store_str, int oneline_len)
{
	char	*tmp;
	int		len;

	len = ft_strchr_gnl(*store_str, '\0') - oneline_len;
	if (len == 0 || ft_strchr_gnl(*store_str, '\n') == 0)
	{
		free(*store_str);
		return (NULL);
	}
	tmp = ft_substr_gnl(*store_str, oneline_len - 1, len);
	free(*store_str);
	return (tmp);
}

char *get_oneline(char **store_str)
{
	int 	oneline_len;
	char	*line;

	if(ft_strchr_gnl(*store_str, '\n') != 0)
		oneline_len = ft_strchr_gnl(*store_str, '\n') + 1;
	else
		oneline_len = ft_strchr_gnl(*store_str, '\0');
	line = malloc ((oneline_len + 1) * sizeof (char));
	if (!line)
	{
		free(line);
		return (NULL);
	}
	line = ft_substr_gnl(*store_str, 0, oneline_len);
	*store_str = store_remaining(store_str, oneline_len);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*store_str;
	char	*oneline;

	store_str = NULL;
	store_str = find_nl(fd, &store_str);
	if (!store_str)
		return (NULL);
	oneline = get_oneline(&store_str);
	return (oneline);
}
