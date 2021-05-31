/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lisanche <lisanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 21:44:38 by lisanche          #+#    #+#             */
/*   Updated: 2021/05/31 16:45:39 by lisanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_res(t_all *s, char *line, int *i)
{
	if (s->win.x != 0 || s->win.y != 0)
		return (-3);
	(*i)++;
	s->win.x = ft_atoi(line, i);
	s->win.y = ft_atoi(line, i);
	if (s->win.x > 2560)
		s->win.x = 2560;
	if (s->win.y > 1400)
		s->win.y = 1400;
	ft_spaceskip(line, i);
	if (s->win.x <= 0 || s->win.y <= 0 || line[*i] != '\0')
		return (-4);
	return (0);
}

int	ft_colors(unsigned int *color, char *line, int *i)
{
	int	r;
	int	g;
	int	b;

	if (*color != NONE)
		return (-5);
	(*i)++;
	r = ft_atoi(line, i);
	(*i)++;
	g = ft_atoi(line, i);
	(*i)++;
	b = ft_atoi(line, i);
	ft_spaceskip(line, i);
	if (line[*i] != '\0' || r > 255 || g > 255 || b > 255)
		return (-6);
	*color = r * 256 * 256 + g * 256 + b;
	return (0);
}

static void	icomplete_otherft(char c, int i, int j, t_all **s)
{
	(*s)->pos.y = (double)i + 0.5;
	(*s)->pos.x = (double)j + 0.5;
	if (c == 'E' || c == 'W')
		(*s)->dir.x = 1;
	else
		(*s)->dir.x = 0;
	if (c == 'W')
		(*s)->dir.x *= -1;
	else
		(*s)->dir.x *= 1;
	if (c == 'S' || c == 'N')
		(*s)->dir.y = 1;
	else
		(*s)->dir.y = 0;
	if (c == 'N')
		(*s)->dir.y *= -1;
	else
		(*s)->dir.y *= 1;
	(*s)->err.p++;
}

void	ft_pos(t_all *s)
{
	char	c;
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (++i < s->map.y)
	{
		while (++j < s->map.x)
		{
			c = s->map.tab[i][j];
			if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
			{
				icomplete_otherft(c, i, j, &s);
			}
		}
		j = -1;
	}
}

int	ft_slist(t_all *s)
{
	int		i;
	int		j;
	int		k;

	if (s->spr != NULL)
		free(s->spr);
	s->spr = malloc(sizeof(t_spr) * s->map.spr);
	if (s->spr == NULL)
		return (-1);
	i = 0;
	j = 0;
	while (j < s->map.y)
	{
		k = 0;
		while (k < s->map.x)
		{
			if (s->map.tab[j][k] == '2')
			{
				s->spr[i].y = (double)j + 0.5;
				s->spr[i++].x = (double)k + 0.5;
			}
			k++;
		}
		j++;
	}
	return (1);
}
