/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: haile <haile@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/18 12:29:34 by haile         #+#    #+#                 */
/*   Updated: 2025/07/02 12:07:58 by haile         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile int	g_signal_back = 0;

void	signal_to_client(int signum)
{
	if (signum == SIGUSR1)
	{
		ft_printf("Message sent successfully");
		exit(EXIT_SUCCESS);
	}
	else if (signum == SIGUSR2)
		g_signal_back = 1;
}

void	wait_for_signal(void)
{
	int	timeout;

	timeout = 0;
	while (!g_signal_back && timeout < 50000)
	{
		usleep(10);
		timeout++;
	}
	if (!g_signal_back)
		ft_error(5);
	g_signal_back = 0;
}

void	ft_client_error(int i)
{
	if (i == 1)
		ft_printf("ERROR: Invalid argument");
	else if (i == 2)
		ft_printf("ERROR: Non - positive PID");
	else if (i == 3)
		ft_printf("ERROR: Sigaction error");
	else if (i == 4)
		ft_printf("ERROR: kill function error");
	else if (i == 5)
		ft_printf("ERROR: Server timeout - no acknowledgement from server");
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
		wait_for_signal();
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
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	pid_server = ft_atoi(av[1]);
	if (pid_server <= 0)
		ft_error(2);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_error(3);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_error(3);
	i = -1;
	while (av[2][++i])
		signal_to_server(av[2][i], pid_server);
	signal_to_server('\0', pid_server);
	pause();
	return (0);
}
