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

int main(void)
{
    ft_putstr_fd("PID: ", 1); //pasas por pantalla el string
    ft_putnbr_fd(getpid(), 1); //pasas por patalla el PID
    ft_putchar_fd('\n', 1); //pasas por pantalla un salto de linea
    

}