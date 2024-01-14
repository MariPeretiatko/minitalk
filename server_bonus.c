/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 00:19:36 by mperetia          #+#    #+#             */
/*   Updated: 2023/12/16 18:46:38 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	display_banner(int pid)
{
	ft_printf("\n\t%s███╗   ███╗██╗███╗   ██╗██╗████████╗ █████╗ ██╗     ██╗██╗\
		%s\n", CYAN, END);
	ft_printf("\t%s██╔████╔██║██║██╔██╗ ██║██║   ██║   ███████║██║     █████╔╝\
		%s \n", CYAN, END);
	ft_printf("\t%s██║╚██╔╝██║██║██║╚██╗██║██║   ██║   ██╔══██║██║     ██╔═██╗\
		%s \n", CYAN, END);
	ft_printf("\t%s██║ ╚═╝ ██║██║██║ ╚████║██║   ██║   ██║  ██║███████╗██║  ██╗\
		%s\n", CYAN, END);
	ft_printf("\t%s╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝\
		%s\n", CYAN, END);
	ft_printf("%s\n\t\tPID: %d%s\t\t\t%sBy: mperetia%s\n", PURPLE, pid, END,
		PURPLE, END);
	ft_printf("\t⊱ ────────────────────── {.⋅ ✯ ⋅.} ─────────────────────── ⊰\
			\n\n");
}

void	print_error_massage(char *str_error)
{
	ft_printf(RED"\n  Error : "RESET);
	ft_printf("%s \n\n", str_error);
}

void	handle_signal(int signal, siginfo_t *info, void *context)
{
	static unsigned char	buff;
	static int				i;
	static int				tmp_pid;

	(void)context;
	buff |= (signal == SIGUSR1);
	i++;
	if (i == 8)
	{
		ft_printf("%c", buff);
		i = 0;
		buff = 0;
	}
	else
		buff <<= 1;
	if (tmp_pid != info->si_pid)
	{
		kill(info->si_pid, SIGUSR1);
		tmp_pid = info->si_pid;
	}
}

int	main(int ac, char *av[])
{
	pid_t				server_pid;
	struct sigaction	sa;

	(void)av;
	if (ac != 1)
	{
		print_error_massage("Wrong number of arguments.»");
		return (0);
	}
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	server_pid = getpid();
	display_banner(server_pid);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
