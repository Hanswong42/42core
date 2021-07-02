/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 08:31:29 by wding-ha          #+#    #+#             */
/*   Updated: 2021/07/02 09:50:51 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	freestr(char **str)
{
	if (str || *str)
	{
		free(*str);
		*str = NULL;
	}
}

void	*ft_calloc(size_t num, size_t size)
{
	int		tol;
	void	*ret;
	int		i;

	tol = num * size;
	ret = malloc(num * size);
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (i < tol)
	{
		((char *)ret)[i] = '\0';
		i++;
	}
	return (ret);
}

int	processline(char **save, char **line)
{
	int		len;
	char	*hold;

	len = 0;
	while ((*save)[len] && (*save)[len] != '\n')
		len++;
	if ((*save)[len] == '\n')
	{
		*line = ft_substr(*save, 0, len);
		hold = ft_strdup(&((*save)[len + 1]));
		freestr(save);
		*save = hold;
	}
	else
	{
		*line = ft_strdup(*save);
		freestr(save);
		return (0);
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*save;
	int			ret;
	char		*str;

	if (fd < 0 || !line || BUFFER_SIZE < 0)
		return (-1);
	if (!save)
		save = ft_calloc(1, 1);
	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret < 0)
			break ;
		buf[ret] = '\0';
		str = ft_strjoin(save, buf);
		freestr(&save);
		save = str;
		if ((ft_strchr(save, '\n')))
			return (processline(&save, line));
	}
	if (ret < 0)
		return (-1);
	return (processline(&save, line));
}
