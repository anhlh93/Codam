/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: haile <haile@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/18 12:29:34 by haile         #+#    #+#                 */
/*   Updated: 2025/06/30 13:12:17 by haile         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

unsigned int	g_bitsend = 0;

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}

void	signal_to_client(int signum)
{
	if (signum == SIGUSR1)
		ft_printf("%d bits succesfully sent", g_bitsend);
}

void	ft_error(int i)
{
	if (i == 1)
		ft_printf("ERROR: Invalid argument");
	else if (i == 2)
		ft_printf("ERROR: Non - positive PID");
	else if (i == 3)
		ft_printf("ERROR: Sigaction error");
	else if (i == 4)
		ft_printf("ERROR: kill function error");
	exit(EXIT_FAILURE);
}

void	signal_to_server(char s, int pid)
{
	int	i;

	i = 7;
	while (i > -1)
	{
		if (s & 1 << i)
		{
			if (kill(pid, SIGUSR1) != 0)
				ft_error(4);
		}
		else
		{
			if (kill(pid, SIGUSR2) != 0)
				ft_error(4);
		}
		usleep(900);
		i--;
	}
}

int	main(int ac, char **av)
{
	int					i;
	int					pid_server;
	struct sigaction	sa;

	if (ac != 3)
		ft_error(1);
	sa.sa_handler = signal_to_client;
	i = 0;
	pid_server = ft_atoi(av[1]);
	if (pid_server <= 0)
		ft_error(2);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_error(3);
	while (av[2][i])
	{
		signal_to_server(av[2][i], pid_server);
		i++;
		g_bitsend += 8;
	}
	signal_to_server('\0', pid_server);
	g_bitsend += 8;
	return (0);
}
