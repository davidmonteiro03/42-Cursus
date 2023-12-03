/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:50:55 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/03 22:15:56 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>	// pthread_create, pthread_detach, pthread_join
						// pthread_mutex_init, pthread_mutex_destroy
						// pthread_mutex_lock, pthread_mutex_unlock
# include <unistd.h>	// usleep
# include <stdio.h>		// printf
# include <stdlib.h>	// malloc, free
# include <sys/time.h>	// gettimeofday

// MACROS
# define FORK "has taken a fork"
# define EATING "is eating"
# define SLEEPING "is sleeping"
# define THINKING "is thinking"
# define DIED "died"

// TYPEDEFS
typedef pthread_t		t_thread;
typedef pthread_mutex_t	t_mutex;

typedef struct s_data
{
	int		num_philos;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		num_meals_per_philo;
	long	start_time;
	t_mutex	*display;
}t_data;

typedef struct s_philo
{
	int			id;
	int			meals_count;
	int			last_meal;
	t_thread	thread;
	t_mutex		*left_fork;
	t_mutex		*right_fork;
	t_data		*data;
}t_philo;

// ACTIONS
int			ph_status(t_philo philo, char *status);
int			ph_eating(t_philo philo);
void		*ph_routine(void *arg);
int			ph_execute(t_philo *philo, int i);

// CHECK
long int	ph_atol(const char *str);
int			ph_check_input(int i, char **argv);

// INIT
t_data		*ph_data(char **argv);
int			ph_init(t_philo **philo, char **argv, int i);

// UTILS
long int	ph_get_time(void);

#endif
