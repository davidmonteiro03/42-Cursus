/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:50:55 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/30 20:57:29 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// pthread_create, pthread_detach, pthread_join, pthread_mutex_init
// pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock
# include <pthread.h>

// usleep
# include <unistd.h>

// printf
# include <stdio.h>

// malloc, free
# include <stdlib.h>

// gettimeofday
# include <sys/time.h>

// MACROS
# define FORK "has taken a fork"
# define EATING "is eating"
# define SLEEPING "is sleeping"
# define THINKING "is thinking"
# define DIED "died"

// TYPEDEFS
typedef pthread_t		t_thread;
typedef pthread_mutex_t	t_mutex;
struct					s_data;

// PHILO STRUCT
typedef struct s_philo
{
	int				id;
	long long		last_meal;
	t_thread		thread;
	t_mutex			*left_fork;
	t_mutex			*right_fork;
	struct s_data	*data;
	struct s_philo	*next;
}t_philo;

// DATA STRUCT
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

// ACTIONS
void		ph_take_forks(t_philo *philo);
void		ph_leave_forks(t_philo *philo);
void		ph_eating(t_philo *philo);
void		ph_thinking(t_philo *philo);
void		ph_sleeping(t_philo *philo);

// CHECK
long		ph_atol(const char *str);
int			ph_check_input(int i, char **av);

// DATA UTILS
int			ph_data_init(t_data **data, char **av);

// DISPLAY
void		ph_status(t_philo *philo, char *status);

// PHILO UTILS
int			ph_philo_init(t_data **data, int i);
void		ph_clear_all(t_data **data, int i);

// EXECUTE
void		*ph_routine(void *arg);
void		ph_execute(t_data *data);

// UTILS
long long	ph_get_time(void);
void		wait_ms(long long time);

#endif
