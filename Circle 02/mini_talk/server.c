/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: haile <haile@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/18 13:27:59 by haile         #+#    #+#                 */
/*   Updated: 2025/06/18 14:14:42 by haile         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_struct    mes;

char    *ft_charjoin(char *s1, char s2)
{
    int size;
    int i;
    char    *new;

    i = 0;
    size = 0;
    while (s1 && s1[size])
        size++;
    new = malloc(sizeof(char) * (size + 2));
    if (new == NULL)
        return (NULL);
    while (s1 && s1[i])
    {
        new[i] = s1[i];
        i++;
    }
    new[i++] = s2;
    new[i] = '\0';
    free(s1);
    return (new);
}

void    ft_error(int i)
{
    if (i == 1)
        ft_printf("ERROR: Invalid argument");
    else if (i == 2)
        ft_printf("ERROR: Non - positive PID");
    else if (i == 3)
        ft_printf("ERROR: Sigaction error");
    else if (i == 4)
        ft_printf("ERROR: kill function error");
    exit (EXIT_FAILURE);
}
void    ft_handler(int signum, siginfo_t *pid_client, void *tmp)
{
    static int i = 0;
    
    void(tmp);
    mes.pid_client = pid_client->si_pid;
    if (signum == SIGUSR1)
    {
        mes.c <<= 1;
        mes.c |= 1;
    }
    else
        mes.c <<= 1;
    i++;
    if (i == 8)
    {
        mes.message = ft_charjoin(mes.message, mes.c);
        if (!mes.c)
        {
            ft_printf("%s\n",mes.message);
            free(mes.message);
            mes.message = NULL;
            kill(mes.pid_client, SIGUSR1);
            usleep(300);
        }
        i = 0;
    }
}
    
int main(void)
{
    struct sigaction    sa;
    int                 pid;

    pid = getpid();
    ft_printf("Current PID of server: %d", pid);
    sa.sa_sigaction = ft_handler;
    sa.sa_flags = SA_SIGINFO;
    mes.message = NULL;
    while (12)
    {
        if (sigaction(SIGUSR1, &sa, NULL) == -1)
            ft_error(3);
        if (sigaction(SIGUSR2, &sa, NULL) == -1)
            ft_error(3);
    }
    pause();
    return (0);
}