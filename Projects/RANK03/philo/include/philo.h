/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:50:55 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/04 09:02:05 by dcaetano         ###   ########.fr       */
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
	int		philo_died;
	t_mutex	*print;
}t_data;

typedef struct s_philo
{
	int			id;
	int			meals_count;
	long		last_meal;
	t_thread	*thread;
	t_mutex		*left_fork;
	t_mutex		*right_fork;
	t_data		*data;
}t_philo;

// CHECK
long int	ph_atol(const char *str);
int			ph_check_input(int i, char **argv);

// CLEAR
int			ph_clear_all(t_philo *philo);

// EXECUTE
int			ph_execute(t_philo *philo);

// INIT
int			ph_init_philos(t_philo **philo, char **argv, int i);

// TIME
long		ph_get_time(void);

#endif
