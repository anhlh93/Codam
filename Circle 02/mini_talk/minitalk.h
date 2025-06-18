/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minitalk.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: haile <haile@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/18 12:24:32 by haile         #+#    #+#                 */
/*   Updated: 2025/06/18 14:11:58 by haile         ########   odam.nl         */
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
    char    c;
    char    *message;
    pid_t   pid_client;
}   t_struct;

/* CLIENT */

/* SERVER */

#endif
