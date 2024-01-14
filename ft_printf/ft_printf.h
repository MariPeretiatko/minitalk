/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 12:41:51 by mperetia          #+#    #+#             */
/*   Updated: 2023/08/25 13:49:58 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>

int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_putnbr(int number);
int	ft_unnbr(unsigned int number);
int	ft_hexnbr(unsigned int number, char is_register);
int	ft_pointer_nbr(unsigned long int number);
int	ft_printf(const char *str, ...);

#endif