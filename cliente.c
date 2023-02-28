/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cliente.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 08:45:02 by jariza-o          #+#    #+#             */
/*   Updated: 2023/02/28 08:45:02 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c && (1 << i) != 0) 
			// (1 << c) mueve la posición del bit a la izquierda, y se mueve una posición sola porque el nº es binario. La primera vez que empieza esta en el final y al empezar el bucle se mueve una posición y ve el primer bit. CUando mueves ve solo de un bit a un bit, no ve los demás de la izq
			// (1 << c) correcto: se deplaza hacia a la izquierda a  la posicion c (que es el contador), y en esa posicion escribe un 1			
			kill(pid, SIGUSR1); //manda una señal al PID indicado cuando el bit que esta viendo es 1
		else
			kill(pid, SIGUSR2); //manda una señal al PID indicado cuando el bit que esta viendo es 0
		else
		usleep(50); //time slepp de 50 micro segundos
	i++;
	}
}

// void	check_signal(int i)
// {
// 	if (i == SIGUSR1)
// 		ft_printf("The message has been sent correctly. \n");
// }

int	main(int argc, char **argv)
{
	int	pid;
	int	n;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]); // paso el PID de char a int
		while (argv[2][n] != '\0')
		{
			send(pid, argv[2][n]);
			n++;
		}
		send(pid, argv[2][n]);
	}
	else
	{
		ft_printf("Wrong Input Format!! \n");
		ft_printf("The correct format is: ./client \"PID\" \"Text Message\" \n");
	}
}
