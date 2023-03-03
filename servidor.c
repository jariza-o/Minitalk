/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   servidor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 08:46:24 by jariza-o          #+#    #+#             */
/*   Updated: 2023/02/28 08:46:24 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int signal, siginfo_t *act, void *oldact) // creo que hay que modificar las dos ultimas variables
	// signal: señal a recibir
	// act y oldact son las estructuras que definen el nuevo y viejo comportamiento para tratar la seña
{
	static unsigned char	byte;
	static int	i;

	(void)oldact; // necesita esto porque esta variable nose usa pero está debido a la estructura de sigaction
	if (signal == SIGUSR1)
		byte |= (1 << i);
	//byte se inicializa la primera vez como 0, es decir, no hay nada. Si la seña recibida es 1, pone un 1 en la posición de i
	i++;
	if (i == 8) //significa que ya ha recibido toda la señal al completo
	{
		if (byte == '\0') // si es caracter nulo imprime un salto de linea porque termina lo recibido
		{
			ft_printf("\n");
			kill(act->si_pid, SIGUSR1); //no entiendo
				//.si_pid: pid del proceso emisor
		}
		else
			ft_printf("%c", byte); // imprime el carcater recibido
		byte = 0;
		i = 0;
			//vuelves a poner byte y i a 0, ya que son estáticas, porque cada vez que llamas a sigaction 
			// se usa la funcion y por byte se llama 8 veces en el bucle del main
	}
}

int	main(void)
{
	struct sigaction	sign;

	
	sign.sa_sigaction = &ft_handler;
	sign.sa_flags = SA_SIGINFO; 
		// .sa_flags: directrices para el proceso cuando recibe la señal.
		// SA_INFO: caundo se escribe SA_INFO se asume que la funcion manejadora está apuntada por sa_sigaction.
	sigemptyset(&sign.sa_mask);
	sigaddset(&sign.sa_mask, SIGUSR1); 
		// sigaddset: Añade una señal a un conjunto, poniendo a uno el bit correspondiente.
		// sa_mask: para cadda señal, mascara de señales a bloquear cuando se ejecuta la función manejadora de esta señal,
		// se añade la señal que está siendo atendida

		// resumen: añade SIGURS1 a la lista .sa_mask, para cuando se ejecute ft_handler no pueda recibir nuevas señales de este tipo.

	sigaddset(&sign.sa_mask, SIGUSR2); // sigaddset: añade una señal a un conjunto de señales
	ft_printf("Welocme to Minitalk Server. \nThe PID Server is: %d \n", getpid()); //escribe el mensaje de bienvenida  y te muestra el PID por pantalla
	while (1)
	{
		sigaction(SIGUSR1, &sign, NULL); // define la acción a realizar cuando se recibe una señal, es la versión POSIX de signal.
		sigaction(SIGUSR2, &sign, NULL);
		pause(); // suspende al proceso solicitante hasta recibir una señal
	}
	return (0);
}

