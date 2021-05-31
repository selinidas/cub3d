/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_ft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lisanche <lisanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:19:52 by lisanche          #+#    #+#             */
/*   Updated: 2021/05/31 17:32:29 by lisanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_map(t_all *s, char *line, int *i)
{
	char	**tmp;
	int		j;

	s->err.m = 1;
	tmp = malloc(sizeof(char *) * (s->map.y + 2));
	if (tmp == NULL)
		return (-11);
	j = -1;
	while (++j < s->map.y)
		tmp[j] = s->map.tab[j];
	tmp[s->map.y] = ft_slab(s, line, i);
	if (tmp[s->map.y] == NULL)
	{
		free(tmp);
		return (-12);
	}
	tmp[s->map.y + 1] = NULL;
	if (s->map.y > 0)
		free(s->map.tab);
	s->map.tab = tmp;
	s->map.y++;
	s->map.x = ft_slablen(s, line);
	if (s->map.x == -1)
		return (-13);
	return (0);
}

static int complete_ftm(t_all **s)
{
	(*s)->spr = malloc(sizeof(t_spr) * (*s)->map.spr);
	if ((*s)->spr == NULL)
		return (-1);
}

int	ft_slist(t_all *s)
{
	int		i;
	int		j;
	int		k;

	if (s->spr != NULL)
		free(s->spr);
	complete_ftm(&s);
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
