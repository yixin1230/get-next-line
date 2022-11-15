/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/02 16:48:59 by yizhang       #+#    #+#                 */
/*   Updated: 2022/11/15 19:02:28 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*find_nl(int fd, char *store_str)
{
	char	buff[BUFFER_SIZE + 1];
	int		i;

	i = 1;
	while (i)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i > 0)
			buff[i] = '\0';
		if (i < 0)
			return (free(store_str), NULL);
		if (i == 0)
			break ;
		if (!store_str)
			store_str = ft_strdup_gnl(buff);
		else
			store_str = ft_strjoin_gnl(store_str, buff);
		if (!store_str)
			return (NULL);
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
	if (len == 0)
		return (free(*store_str), NULL);
	tmp = ft_substr_gnl(*store_str, oneline_len, len);
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
	*store_str = store_remaining(store_str, oneline_len);
	return (oneline);
}

char	*get_next_line(int fd)
{
	static char	*store_str;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	store_str = find_nl(fd, store_str);
	if (store_str != NULL)
		return (get_oneline(&store_str));
	return (NULL);
}
