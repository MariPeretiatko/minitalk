/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 00:20:23 by mperetia          #+#    #+#             */
/*   Updated: 2023/12/16 19:20:42 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <signal.h>
# include "ft_printf/ft_printf.h"

# define END "\033[0m"
# define RESET   "\033[0m"
# define RED     "\033[1;31m"
# define YELLOW  "\033[1;33m"
# define WHITE   "\033[1;37m"
# define BYELLOW	"[\033[1;33m"
# define PURPLE 	"\033[35m"
# define CYAN    "\033[36m"

#endif