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
			store_str = ft_strjoin_gnl(buff);
		if (ft_strchr_gnl(store_str, '\n') != 0)
			return (store_str);
	}
	return (store_str);
}

static t_list *get_l(char *store_str)
{
	t_list	*node;
	int		i;

	i = 0;
	whlie (store_str[i] != '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	line = substr(store_str,i)
}

char	*get_next_line(int fd)
{
	char	*buff;
	char	*store_str;
	char	*oneline;

	store_str = find_nl(fd,store_str);
	oneline = get_l(store_str);
	return (oneline);
}
