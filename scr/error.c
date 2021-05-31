/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lisanche <lisanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 21:14:49 by lissettesan       #+#    #+#             */
/*   Updated: 2021/05/30 16:21:52 by lisanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_spaceskip(char *line, int *i)
{
	while ((line[*i] == ' ' || line[*i] == '\t' || line[*i] == '\n')
		|| (line[*i] == '\r' || line[*i] == '\v' || line[*i] == '\f'))
		(*i)++;
	return (1);
}

int	ft_atoi(char *line, int *i)
{
	int	num;

	num = 0;
	ft_spaceskip(line, i);
	while (line[*i] >= '0' && line[*i] <= '9')
	{
		num = num * 10 + (line[*i] - 48);
		(*i)++;
	}
	return (num);
}

int	ft_strerror(int err)
{
	if (err == -1)
		write(2, "Error UPS! No se puede abrir el archivo (FD)\n", 44);
	if (err == -2)
		write(2, "Error UPS! No se encuentra el archivo (GNL)\n", 43);
	if (err == -3)
		write(2, "Error UPS! La resolucion esta duplicada\n", 39);
	if (err == -4)
		write(2, "Error UPS! La resoslucion es incorrecta\n", 39);
	if (err == -5)
		write(2, "Error UPS! E suelo/techo estan duplicados\n", 42);
	if (err == -6)
		write(2, "Error UPS! El suelo/techo son invalidos\n", 37);
	if (err == -7)
		write(2, "Error UPS! Tesxtura duplicada\n", 29);
	if (err == -8)
		write(2, "Error UPS! Falla malloc texturas\n", 32);
	if (err == -9)
		write(2, "Error UPS! La textura de la imagen es incorrecta\n", 48);
	if (err == -10)
		write(2, "Error UPS! Linea invalida en archivo\n", 36);
	if (err == -11)
		write(2, "Error UPS! Falla malloc mapa\n", 28);
	return (-1);
}

int	ft_strerror2(int err)
{
	if (err == -12)
		write(2, "Error UPS! Mapa incorrecto\n", 30);
	if (err == -13)
		write(2, "Error UPS! El mapa no es un rectagulo\n", 37);
	if (err == -14)
		write(2, "Error UPS! No se especifica la resolucion\n", 41);
	if (err == -15)
		write(2, "Error UPS! No se encuentra la textura\n", 37);
	if (err == -16)
		write(2, "Error UPS! No se encuentra el color techo/floor\n", 47);
	if (err == -17)
		write(2, "Error UPS! No hay posicion inicial\n", 34);
	if (err == -18)
		write(2, "Error UPS! Multiples posiciones de inicios\n", 42);
	if (err == -19)
		write(2, "Error UPS! El mapa no tiene paredes\n", 34);
	return (-1);
}
