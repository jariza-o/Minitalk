/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 19:31:59 by jariza-o          #+#    #+#             */
/*   Updated: 2022/11/28 20:02:40 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include   <stdarg.h>
# include	<stdlib.h>
# include	<unistd.h>

# define HEX_LOW_BASE "0123456789abcdef"
# define HEX_UPP_BASE "0123456789ABCDEF"

void	ft_printchar(char c, int *count);
void	ft_printstr(char *str, int *count);
void	ft_printnbr(int n, int *count);
void	ft_printunsig(unsigned int n, int *count);
void	ft_hex(unsigned long long n, int *count, char *base);

void	ft_control(va_list args, char *str, int *count);
int		ft_printf(char const *str, ...);

#endif
