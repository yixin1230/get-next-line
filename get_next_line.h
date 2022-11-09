/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/02 16:48:01 by yizhang       #+#    #+#                 */
/*   Updated: 2022/11/08 14:29:33 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

char	*get_next_line(int fd);
int		ft_strchr_gnl(char *str,char c);
char	*ft_strdup_gnl(char *s);
char	*ft_strjoin_gnl(char *dst, char *src);
char	*ft_substr_gnl(char *store_str, int start , int len);

#endif