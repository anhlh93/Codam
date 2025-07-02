/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: haile <haile@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/18 13:27:59 by haile         #+#    #+#                 */
/*   Updated: 2025/07/02 10:37:38 by haianhle      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_struct	g_mes;

void	ft_error(int i)
{
	if (i == 1)
		ft_printf("ERROR: Invalid argument");
	else if (i == 2)
		ft_printf("ERROR: Bad PID");
	else if (i == 3)
		ft_printf("ERROR: Sigaction error");
	else if (i == 4)
		ft_printf("ERROR: kill function error");
	else if (i == 6)
		ft_printf("ERROR: Memory allocation failed\n");
	exit(EXIT_FAILURE);
}

void	ft_addchar(void)
{
	char	*temp;

	temp = ft_charjoin(g_mes.message, g_mes.c);
	if (!temp)
		ft_error(6);
	g_mes.message = temp;
}

void	ft_handler(int signum, siginfo_t *pid_client, void *tmp)
{
	static int	i = 0;

	(void)tmp;
	g_mes.pid_client = pid_client->si_pid;
	g_mes.c <<= 1;
	if (signum == SIGUSR1)
		g_mes.c |= 1;
	if (kill(g_mes.pid_client, SIGUSR2) == -1)
		ft_error(4);
	if (++i == 8)
	{
		if (g_mes.c == '\0')
		{
			if(g_mes.message)
			{
				ft_printf("%s\n", g_mes.message);
				free(g_mes.message);
				g_mes.message = NULL;
			}
			else
			{
				ft_printf("\n");
			}
			if (kill(g_mes.pid_client, SIGUSR1) == -1)
				ft_error(4);
		}
		else
			ft_addchar();
		i = 0;
		g_mes.c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	pid = getpid();
	ft_printf("Current PID of server: %d\n", pid);
	g_mes.message = NULL;
	g_mes.c = 0;
	g_mes.pid_client = 0;
	sa.sa_sigaction = ft_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_error(3);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_error(3);
	while (12)
	{
		pause();
	}
	return (0);
}
