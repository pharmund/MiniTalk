/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharmund <pharmund@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:59:33 by pharmund          #+#    #+#             */
/*   Updated: 2022/02/18 19:48:04 by pharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	string_transmit(unsigned char c, int pid)
{
	int	array[8];
	int	i;

	i = 7;
	while (c > 0)
	{
		if (c % 2 == 1)
			array[i] = 1;
		else
			array[i] = 0;
		c = c / 2;
		i--;
	}
	while (i >= 0)
		array[i--] = 0;
	i = 0;
	while (i < 8)
	{
		if (array[i] == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i++;
		usleep(300);
	}
}

int	main(int argc, char **argv)
{
	long int	pid;
	int			i;

	i = 0;
	if (argc != 3)
		return (0);
	pid = ft_atoi(argv[1]);
	if (pid == 0)
	{
		write(1, "PID first,then enter the string.\n", 33);
		exit(EXIT_FAILURE);
	}
	while (argc == 3 && argv[2][i])
	{
		string_transmit(argv[2][i], pid);
		i++;
	}
	return (0);
}
