/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/02 16:48:01 by yizhang       #+#    #+#                 */
/*   Updated: 2022/11/07 17:01:15 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 10

typedef struct t_list 
{
	char	*content;
	struct	t_list *next;
}t_list;

char	*get_next_line(int fd);
int		ft_strchr_gnl(const char *str,char c);
int 	ft_strlen_gnl(const char *str);
char	*ft_strdup_gnl(char *s);
char	*ft_strjoin_gnl(char *dst, char *src);

#endif