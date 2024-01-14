/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 12:54:15 by mperetia          #+#    #+#             */
/*   Updated: 2023/10/29 21:36:52 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	function_selection(char symbol, va_list factor)
{
	int	count;

	count = 0;
	if (symbol == 'c')
		count += ft_putchar(va_arg(factor, int));
	else if (symbol == 's')
		count += ft_putstr(va_arg(factor, char *));
	else if (symbol == 'p')
	{
		count += ft_putstr("0x");
		count += ft_pointer_nbr(va_arg(factor, unsigned long int));
	}
	else if (symbol == 'd' || symbol == 'i')
		count += ft_putnbr(va_arg(factor, int));
	else if (symbol == 'u')
		count += ft_unnbr(va_arg(factor, int));
	else if (symbol == 'x' || symbol == 'X')
		count += ft_hexnbr(va_arg(factor, int), symbol);
	else if (symbol == '%')
		count += ft_putchar('%');
	else
		count += ft_putchar(symbol);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	int		i;
	va_list	factor;

	count = 0;
	i = 0;
	va_start(factor, str);
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i] == '\0')
				return (i);
			count += function_selection(str[i + 1], factor);
			i++;
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(factor);
	return (count);
}

/*int main()
{
	
	//ft_printf("\001\002\007\v\010\f\r\n");
	//printf("%s", "          hushd         121212");
	//printf("% d", 8);
	//printf("% f", -8.1);
	//printf("%--s", "hushd");
	//ft_printf("%c%c\n", 'u', 'i');
	//ft_printf("%d%c\n",125,'i');
	//printf("%d \n", sum(4, 1, 2, 3, 4));
	//printf("%d \n", sum(5, 12, 21, 13, 4, 5));
	//int n = ft_printf("%d\n%c\n%s\n", 77, 'c', "zxcv");
	//printf("%d\n", n);
	return (0);
}*/