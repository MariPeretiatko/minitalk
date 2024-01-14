/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 13:20:02 by mperetia          #+#    #+#             */
/*   Updated: 2023/08/25 13:20:26 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer_nbr(unsigned long int number)
{
	int	count;

	count = 0;
	if (number < 10)
	{
		count = count + ft_putchar(number + 48);
	}
	else if (number < 16)
	{
		count = count + ft_putchar(number + 87);
	}
	else
	{
		count += ft_pointer_nbr(number / 16);
		count += ft_pointer_nbr(number % 16);
	}
	return (count);
}
