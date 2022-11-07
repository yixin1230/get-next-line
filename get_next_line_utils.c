/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/02 16:51:11 by yizhang       #+#    #+#                 */
/*   Updated: 2022/11/07 15:49:25 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
int		ft_strchr_gnl(const char *str,char c);
int 	ft_strlen_gnl(const char *str);
char	*ft_strdup_gnl(char *s);
char	*ft_strjoin_gnl(char *dst, char *src);

int	ft_strchr_gnl(const char *str,char c)
{
	while(*str)
	{
		if(*str == c)
			return (1);
		str++;
	}
	return (0);
}

int ft_strlen_gnl(const char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

char	*ft_strdup_gnl(char *s)
{
	char	*str;
	int		len;

	len = 0;
	if(!s)
		return (NULL);
	len = ft_strlen_gnl(s);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while(len >= 0)
	{
		str[len] = s[len];
		len--;
	}
	return (str);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*ret;
	int		len;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen_gnl(s1) + ft_strlen_gnl(s2);
	ret = malloc((len + 1) * sizeof(char));
	ret[len] = '\0';
	i = 0;
	while (s1[i])
	{
		ret[i] = s1[i]; 
		i++;
	}
	len = i;
	i = 0;
	while (s2[i])
	{
		ret[len + i] = s2[i];
		i++;
	}
	return (ret);
}