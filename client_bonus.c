/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 00:19:30 by mperetia          #+#    #+#             */
/*   Updated: 2023/12/16 19:49:19 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_error_massage(char *str_error)
{
	ft_printf(RED"\n  ERROR » "RESET);
	ft_printf("%s \n\n", str_error);
}

void	print_massage(int signal)
{
	ft_printf(PURPLE"\n  SUCCESS » "RESET);
	ft_printf("message received by server » (%d)\n\n", signal);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	is_neg;
	int	res;

	if (!str)
		return (0);
	i = 0;
	is_neg = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		is_neg = -1;
	if (is_neg == -1 || str[i] == '+')
		i++;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
		res = (res * 10) + (str[i++] - '0');
	return (res * is_neg);
}

void	foo(unsigned char octet, pid_t server_pid)
{
	int				i;
	unsigned char	octet_tmp;

	octet_tmp = octet;
	i = 8;
	while (i-- > 0)
	{
		octet_tmp = octet >> i;
		if (octet_tmp % 2 == 0)
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		usleep(100);
	}
}

int	main(int ac, char *av[])
{
	pid_t	server_pid;
	int		i;
	int		bit;

	bit = 0;
	i = 0;
	if (ac != 3)
	{
		print_error_massage("Wrong number of arguments. 1 - PID. 2 - string");
		return (0);
	}
	server_pid = ft_atoi(av[1]);
	if (kill(server_pid, 0))
	{
		print_error_massage("PID entered incorrectly");
		return (0);
	}
	signal(SIGUSR1, print_massage);
	while (av[2][i])
	{
		foo(av[2][i], server_pid);
		i++;
	}
	return (0);
}
