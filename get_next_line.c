/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/02 16:48:59 by yizhang       #+#    #+#                 */
/*   Updated: 2022/11/14 13:22:50 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
static char	*find_nl(int fd, char *store_str)
{
	int		i;
	char	buff[BUFFER_SIZE + 1];

	i = 1;
	while (i)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i < 0)
			return (free(store_str), NULL);
		if (i == 0)
			break ;
		buff[i] = '\0';
		if (!store_str)
			store_str = ft_strdup_gnl(buff);
		else
			store_str = ft_strjoin_gnl(store_str, buff);
		if (ft_strchr_gnl(store_str, '\n'))
			return (store_str);
	}
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
	if (!tmp)
		return (tmp);
	return (free(*store_str), tmp);
}

static char	*get_oneline(char **store_str)
{
	int		oneline_len;
	char	*oneline;

	if (ft_strchr_gnl(*store_str, '\n'))
		oneline_len = ft_len_gnl(*store_str, '\n') + 1;
	else
		oneline_len = ft_len_gnl(*store_str, '\0');
	oneline = ft_substr_gnl(*store_str, 0, oneline_len);
	if (!oneline)
		return (free (*store_str),oneline);
	*store_str = store_remaining(store_str, oneline_len);
	return (oneline);
}

char	*get_next_line(int fd)
{
	static char	*store_str;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	store_str = find_nl(fd, store_str);
	if (!store_str)
		return (NULL);
	return (get_oneline(&store_str));
}
