/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lisanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 21:46:42 by lisanche          #+#    #+#             */
/*   Updated: 2021/05/29 21:36:50 by lisanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	icomplete_theseft(int *i, char *line, t_all **s)
{
	if ((line[*i] == '1' || (*s)->err.m == 1) && line[*i] != '\0')
		(*s)->err.n = ft_map(*s, line, i);
	else if (line[*i] == 'R' && line[*i + 1] == ' ')
		(*s)->err.n = ft_res(*s, line, i);
	else if (line[*i] == 'N' && line[*i + 1] == 'O' && line[*i + 2] == ' ')
		(*s)->err.n = ft_texture(*s, &(*s)->tex.n, line, i);
	else if (line[*i] == 'S' && line[*i + 1] == 'O' && line[*i + 2] == ' ')
		(*s)->err.n = ft_texture(*s, &(*s)->tex.s, line, i);
	else if (line[*i] == 'W' && line[*i + 1] == 'E' && line[*i + 2] == ' ')
		(*s)->err.n = ft_texture(*s, &(*s)->tex.w, line, i);
	else if (line[*i] == 'E' && line[*i + 1] == 'A' && line[*i + 2] == ' ')
		(*s)->err.n = ft_texture(*s, &(*s)->tex.e, line, i);
	else if (line[*i] == 'S' && line[*i + 1] == ' ')
		(*s)->err.n = ft_texture(*s, &(*s)->tex.i, line, i);
	else if (line[*i] == 'F' && line[*i + 1] == ' ')
		(*s)->err.n = ft_colors(&(*s)->tex.f, line, i);
	else if (line[*i] == 'C' && line[*i + 1] == ' ')
		(*s)->err.n = ft_colors(&(*s)->tex.c, line, i);
}

int	ft_line(t_all *s, char *line)
{
	int		i;

	i = 0;
	ft_spaceskip(line, &i);
	icomplete_theseft(&i, line, &s);
	if (ft_spaceskip(line, &i) && s->err.n == 0 && line[i] != '\0')
		return (ft_strerror(-10));
	if (s->err.n < 0)
		return (ft_strerror(s->err.n));
	return (0);
}

static int	icomplete_aft(char **line, int read_size, char **stock)
{
	*line = get_line(*stock);
	if (*line == NULL)
		return (-3);
	if (read_size == 0)
		free(*stock);
	if (read_size == 0)
		return (0);
	*stock = stock_trim(*stock);
	if (*stock == NULL)
		return (-3);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	int			read_size;
	char		buf[4096];
	static char	*stock = NULL;

	if (line == NULL || fd < 0)
		return (-3);
	*line = NULL;
	read_size = 1;
	while (!(newline_check(stock, read_size)))
	{
		read_size = read(fd, buf, 4095);
		if (read_size == -1)
			return (-3);
		buf[read_size] = '\0';
		stock = buf_join(stock, buf);
		if (stock == NULL)
			return (-3);
	}
	return (icomplete_aft(line, read_size, &stock));
}

int	ft_parse(t_all *s, char *cub)
{
	char	*line;
	int		fd;
	int		ret;

	ret = 1;
	fd = open(cub, O_RDONLY);
	if (fd == -1)
		return (ft_strerror(-1));
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		if (ft_line(s, line) == -1)
			ret = -1;
		free(line);
	}
	close(fd);
	if (ret == -1 || ret == -3)
		return (ft_strerror(ret + 1));
	ft_pos(s);
	s->spr = NULL;
	ft_slist(s);
	return (ft_parcheck(s));
}
