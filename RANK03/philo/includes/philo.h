/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:44:08 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/07 15:49:06 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_info
{
	int	ttd;
	int	tte;
	int	tts;
}t_info;

typedef struct s_philo
{
	pthread_t		id;
	pthread_mutex_t	lf;
	pthread_mutex_t	rf;
}t_philo;

////////////////////////////////////////////////////////////////////////////////
//                                    UTILS                                   //
////////////////////////////////////////////////////////////////////////////////

int		philo_atoi(const char *nptr);

////////////////////////////////////////////////////////////////////////////////
//                                 PHILO UTILS                                //
////////////////////////////////////////////////////////////////////////////////

void	philo_info(t_info *info, char **av);
void	*philo_create(void *arg);
void	create_philo(t_philo **philo, int num);
void	join_philo(t_philo **philo, int num);
void	free_philo(t_philo **philo, int num);

#endif
