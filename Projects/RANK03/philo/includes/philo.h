/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:50:55 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/23 10:58:38 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdbool.h>

# define FORK "has taken a fork 🍴"
# define EAT "is eating 🍝"
# define THINK "is thinking 💭"
# define SLEEP "is sleeping 💤"
# define DIED "died 💀"

typedef pthread_mutex_t	t_mutex;
typedef pthread_t		t_th;

/* ERRORS */
int		ph_error(char *error);

/* PARSER */
long	ph_atol(const char *nptr);
int		ph_parse_args(char **av);
int		ph_parse_range(char **av);

#endif
