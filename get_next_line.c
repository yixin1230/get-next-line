/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/02 16:48:59 by yizhang       #+#    #+#                 */
/*   Updated: 2022/11/07 17:17:55 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*find_nl(int fd,char *store_str)
{
	int		i;
	char	*buff;
	
	i = 1;
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
	{
		free(buff);
		return(NULL);
	}
	while (i)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i < 0)
			return (NULL);
		if (i == 0)
			break;
		if(!store_str)
			store_str = ft_strdup_gnl(buff);
		else
			store_str = ft_strjoin_gnl(store_str, buff);
		if (ft_strchr_gnl(store_str, '\n') != 0)
			return (store_str);
	}
	return (store_str);
}

char *get_l(char *store_str)
{
	int		i;
	int 	len;
	char	*line;
	char	*tmp;

	i = 0;
	len = 0;
	while (store_str[len] != '\n')
		len++;
	while (store_str[len + i] != '\0')
		i++;
	line = malloc((len + 2) * sizeof(char));
	tmp = malloc((i + 1) * sizeof(char));
	line[len + 1] = '\0';
	i = len;
	while(i >= 0)
	{
		line[i] = store_str[i];
		i--;
	}
	len += 1;
	i = 0;
	while (store_str[len + i] != '\0')
	{
		i++;
		tmp[i] = store_str[len + i];
	}
	store_str = tmp;
	return (line);
}

char	*get_next_line(int fd)
{
	char		*store_str;
	static char	*oneline;

	store_str = NULL;
	store_str = find_nl(fd,store_str);
	oneline = get_l(store_str);
	return (oneline);
}
