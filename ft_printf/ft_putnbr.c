/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 13:17:43 by mperetia          #+#    #+#             */
/*   Updated: 2023/08/25 13:18:07 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int number)
{
	int	count;

	count = 0;
	if (number == INT_MIN)
		return (write(1, "-2147483648", 11));
	if (number < 0)
	{
		count += ft_putchar('-');
		number = -number;
	}
	if (number < 10)
		count += ft_putchar(number + 48);
	else
	{
		count += ft_putnbr(number / 10);
		count += ft_putnbr(number % 10);
	}
	return (count);
}
