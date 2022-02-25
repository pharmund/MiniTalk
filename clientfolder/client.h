/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharmund <pharmund@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:23:52 by pharmund          #+#    #+#             */
/*   Updated: 2022/02/21 21:57:24 by pharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <stdio.h>

int		main(int argc, char *argv[]);
int		ft_atoi(const char *s);
void	string_transmit(unsigned char c, int pid);

#endif