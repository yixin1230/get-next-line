/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: yizhang <yizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/02 16:51:11 by yizhang       #+#    #+#                 */
/*   Updated: 2022/11/14 13:17:23 by yizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_len_gnl(char *str, char c);
char	*ft_strdup_gnl(char *s);
char	*ft_strjoin_gnl(char *dst, char *src);
char	*ft_substr_gnl(char *store_str, int start, int len);
char	*ft_strchr_gnl(char *str, char c);

int	ft_len_gnl(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	if (c == '\0')
		return (i);
	return (0);
}

char	*ft_strchr_gnl(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (str + i);
		i++;
	}
	if (c == '\0')
		return (str + i);
	return (NULL);
}

char	*ft_strdup_gnl(char *s)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_len_gnl(s, '\0');
	if (len == 0)
		return (free(s),NULL);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (free(s),NULL);
	while (len > i)
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

	if (!s2)
		return (NULL);
	len = ft_len_gnl(s1, '\0') + ft_len_gnl(s2, '\0');
	ret = malloc((len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	len = 0;
	while (s1[len])
	{
		ret[len] = s1[len];
		len++;
	}
	i = 0;
	while (s2[i])
	{
		ret[len + i] = s2[i];
		i++;
	}
	ret[len + i] = '\0';
	free (s1);
	return (ret);
}

char	*ft_substr_gnl(char *s, int start, int len)
{
	char	*s1;
	int		s_len;
	int		i;

	i = 0;
	s_len = ft_len_gnl(s, '\0');
	if (!len)
		return (NULL);
	if (start >= s_len || len == 0 || s_len == 0)
		return (NULL);
	if (len > s_len - start)
		len = s_len - start;
	s1 = malloc((len + 1) * sizeof(char));
	if (s1 == NULL)
		return (s1);
	while (i < len)
	{
		s1[i] = s[start + i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
