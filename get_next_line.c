/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/02 16:48:59 by yizhang       #+#    #+#                 */
/*   Updated: 2022/11/11 10:12:02 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

static char	*find_nl(int fd,char *store_str)
{
	int		i;
	char	buff[BUFFER_SIZE + 1];
	
	i = 1;
	while (i)
	{
		i = read(fd, buff, BUFFER_SIZE);
		buff[i] = '\0';
		if (i < 0)
			return (NULL);
		if (i == 0)
			break;
		if(!store_str)
		{
			store_str = ft_strdup_gnl(buff);
			//printf("1:%s\n",store_str);
		}
		else
		{
			store_str = ft_strjoin_gnl(store_str, buff);
			//printf("2:%s\n",store_str);
		}
		if (ft_strchr_gnl(store_str, '\n'))
		{
			//printf("3:%s\n",store_str);
			return (store_str);	
		}
	}
	//printf("4:%s\n",store_str);
	return (store_str);
}

static char	*store_remaining(char **store_str, int oneline_len)
{
	char	*tmp;
	int		len;

	len = ft_len_gnl(*store_str, '\0') - oneline_len;
	if (len == 0 || !ft_strchr_gnl(*store_str, '\n'))
	{
		free(*store_str);
		return (NULL);
	}
	tmp = ft_substr_gnl(*store_str, oneline_len, len);
	//printf("tmp:%s\n",tmp);
	free(*store_str);
	return (tmp);
}

static char *get_oneline(char **store_str)
{
	int 	oneline_len;
	char	*line;

	if(ft_strchr_gnl(*store_str, '\n'))
		oneline_len = ft_len_gnl(*store_str, '\n') + 1;
	else
		oneline_len = ft_len_gnl(*store_str, '\0');
	line = malloc ((oneline_len + 1) * sizeof (char));
	if (!line)
	{
		free(line);
		return (NULL);
	}
	line = ft_substr_gnl(*store_str, 0, oneline_len);
	*store_str = store_remaining(store_str, oneline_len);
	//printf("store_str:%s\n",*store_str);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*store_str;
	char	*oneline;

	store_str = find_nl(fd, store_str);
	if (!store_str)
		return (NULL);
	oneline = get_oneline(&store_str);
	//printf("store_str2:%s\n",store_str);
	return (oneline);
}
