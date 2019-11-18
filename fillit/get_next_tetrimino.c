/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_tetrimino.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 15:55:35 by tbergkul          #+#    #+#             */
/*   Updated: 2019/11/18 11:31:20 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_next_line(const int fd, char **line, char **str)
{
	/*int		i;

	i = 0;
	while (str[fd][i] != '\0')
		i++;*/
	*line = ft_strdup(str[fd]);
	//printf("line:\n%s", *line);
	ft_strdel(&str[fd]);
	return (1);
}

static int	ft_return(const int fd, char **line, char **str, int x)
{
	if (x < 0)
		return (-1);
	else if (x == 0 && str[fd] == NULL)
		return (0);
	else
		return (ft_next_line(fd, line, str));
}

int			get_next_tetrimino(const int fd, char **line)
{
	int			x;
	char		current[BUFF_SIZE + 1];
	//char		*temp;
	static char	*str[10240];

	if ((fd < 0 || fd > 10240) || !line)
		return (-1);
	if ((x = read(fd, current, BUFF_SIZE)) > 0)
	{
		//printf("read\n");
		current[x] = '\0';
		if (!str[fd])
			str[fd] = ft_strdup(current);
		/*else
		{
			temp = ft_strjoin(str[fd], current);
			free(str[fd]);
			str[fd] = temp;
		}*/
		//if (ft_strlen(str[fd]) == 20)
		//	break ;
	}
	//printf("str[fd]:\n%s", str[fd]);
	return (ft_return(fd, line, str, x));
}
