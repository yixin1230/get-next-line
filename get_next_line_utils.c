/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/02 16:51:11 by yizhang       #+#    #+#                 */
/*   Updated: 2022/11/08 14:08:28 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int		ft_strchr_gnl(char *str,char c);
char	*ft_strdup_gnl(char *s);
char	*ft_strjoin_gnl(char *dst, char *src);
char	*ft_substr_gnl(char *store_str, int start , int len);

int	ft_strchr_gnl(char *str, char c)//return c 的具体位置
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	if (c == '\0')
		return (i);
	return (0);
}

char	*ft_strdup_gnl(char *s)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	if(!s)
		return (NULL);
	len = ft_strchr_gnl(s,'\0');
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while(len > i)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*ret;
	int		len;
	int		i;

	if (!s1 && !s2)
		return (NULL);
	len = ft_strchr_gnl(s1, '\0') + ft_strchr_gnl(s2, '\0');
	ret = malloc((len + 1) * sizeof(char));
	if(!ret)
		return (NULL);
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
	ret[len + i] = '\0';
	return (ret);
}

char	*ft_substr_gnl(char *store_str, int start , int len)
{
	char	*s;
	int		i;

	i = 0;
	s = malloc((len + 1) * sizeof(char));
	if (!s || !store_str || !len)
		return (NULL);
	while (i < len)
	{
		s[i] = store_str[start + i];
		i++;
	}
	s[i] = '\0';
	return (s);
}