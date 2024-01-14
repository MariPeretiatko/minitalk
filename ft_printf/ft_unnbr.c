/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 13:18:25 by mperetia          #+#    #+#             */
/*   Updated: 2023/08/25 13:23:38 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unnbr(unsigned int number)
{
	int	count;

	count = 0;
	if (number < 10)
		count += ft_putchar(number + 48);
	else
	{
		count += ft_unnbr(number / 10);
		count += ft_unnbr(number % 10);
	}
	return (count);
}
