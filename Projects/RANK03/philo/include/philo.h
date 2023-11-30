/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:50:55 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/30 20:04:15 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

typedef pthread_t		t_thread;
typedef pthread_mutex_t	t_mutex;
struct					s_data;

typedef struct s_philo
{
	int				id;
	t_thread		thread;
	t_mutex			*left_fork;
	t_mutex			*right_fork;
	struct s_data	*data;
	struct s_philo	*next;
}t_philo;

typedef struct s_data
{
	int			num_philos;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			num_of_meals_for_ph;
	t_philo		*philos;
	t_mutex		*forks;
	long long	start;
}t_data;

// actions
void		ph_take_forks(t_philo *philo);
void		ph_leave_forks(t_philo *philo);

// check
long		ph_atol(const char *str);
int			ph_check(int i, char **av);

// data utils
int			ph_data_init(t_data **data, char **av);

// philo utils
int			ph_philo_init(t_data **data, int i);
void		ph_clear(t_data **data, int i);

// execute
void		*ph_routine(void *arg);
void		ph_execute(t_data *data);

// utils
long long	ph_get_time(void);
void		wait_ms(long long time);

#endif
