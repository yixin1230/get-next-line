/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/02 16:48:59 by yizhang       #+#    #+#                 */
/*   Updated: 2022/11/07 20:26:28 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

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
		if (ft_strchr_gnl(store_str, '\n') != NULL)
			return (store_str);
	}
	return (store_str);
}

char *get_l(char *store_str)
{
	int		i;
	int 	len;
	char	*tmp;
	char	*line;

	i = 0;
	len = 0;
	while(store_str[i] == '\n')
		i++;
	while (store_str[i + len] != '\n')
		len++;
	line = ft_substr_gnl(store_str, i , len);
	len = i + len;
	i = 0;
	while (store_str[len + i] != '\0')
		i++;
	tmp = ft_substr_gnl(store_str, len + 1 , i);
	free(store_str);
	store_str = tmp;
	printf("store_str:%s\n",store_str);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*store_str;
	char	*oneline;

	store_str = NULL;
	store_str = find_nl(fd,store_str);
	oneline = get_l(store_str);
	return (oneline);
}
