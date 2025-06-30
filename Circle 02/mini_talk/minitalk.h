/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: haile <haile@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/18 12:24:32 by haile         #+#    #+#                 */
/*   Updated: 2025/06/30 10:42:31 by haianhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>     // For getpid(), usleep(), pause()
# include <stdlib.h>     // For malloc(), free(), exit(), EXIT_FAILURE
# include <signal.h>     // For signal handling
# include "ft_printf/ft_printf.h"

/* STRUCTURE*/
typedef struct s_struct
{
	char	c;
	char	*message;
	pid_t	pid_client;
}	t_struct;

/* CLIENT */
int		ft_atoi(const char *str);
void	signal_to_client(int signum);
void	ft_error(int i);
void	signal_to_server(char s, int pid);
char	*ft_charjoin(char *s1, char s2);
void	ft_sperror(int i);
void	ft_handler(int signum, siginfo_t *pid_client, void *tmp);

#endif
