/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamoud <hhamoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 14:52:10 by hhamoud           #+#    #+#             */
/*   Updated: 2023/03/25 17:42:27 by hhamoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(const char *s)
{
	int i;
	
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		i++;
	}
	return(i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		s_len;
	int		ss_len;

	if (!s1)
	return (NULL);
	s_len = ft_strlen(s1);
	ss_len = ft_strlen(s2);
	ptr = malloc(sizeof(char) * (s_len + ss_len + 1));
	if (!ptr)
		return (NULL);
	s_len = 0;
	ss_len = 0;
	while (s1 && s1[s_len] != '\0')
	{
		ptr[s_len] = s1[s_len];
		s_len++;
	}
	while (s2[ss_len] != '\0')
		ptr[s_len++] = s2[ss_len++];
	ptr[s_len] = '\0';
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*temp;

	i = 0;
	if (!s)
		return (0);
	temp = (char *)s;
	while (temp[i] != '\0' && temp[i] != (unsigned char)c)
		i++;
	if (temp[i] == (unsigned char)c)
		return (temp + i);
	return (0);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		i;

	i = 0;
	dest = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	if (!dest)
		return (NULL);
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
