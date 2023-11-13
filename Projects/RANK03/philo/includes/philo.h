/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:50:55 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/13 08:15:14 by dcaetano         ###   ########.fr       */
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

typedef pthread_t		t_th;
typedef pthread_mutex_t	t_mutex;
typedef time_t			t_time;

struct					s_inf;

typedef struct s_ph
{
	struct s_inf	*inf;
}t_ph;

typedef struct s_inf
{
	int		num_ph;
	int		time_die;
	int		time_eat;
	int		time_sleep;
	int		num_time_meals_ph;
	t_ph	*ph;
}t_inf;

/* ************************************************************************** */
/*                                    CHECK                                   */
/* ************************************************************************** */

int		ph_atoi(const char *str);
bool	check_args(int ac, char **av);

/* ************************************************************************** */
/*                                   ERRORS                                   */
/* ************************************************************************** */

int		error(char *error);

/* ************************************************************************** */
/*                                    INIT                                    */
/* ************************************************************************** */

int		init_inf(t_inf *inf, int ac, char **av);

#endif
