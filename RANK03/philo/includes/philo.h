/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:44:08 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/07 13:37:46 by dcaetano         ###   ########.fr       */
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
	long int	ttd;
	long int	tte;
	long int	tts;
}t_info;

typedef struct s_philo
{
	t_info			info;
	int				pos;
	pthread_t		id;
}t_philo;

////////////////////////////////////////////////////////////////////////////////
//                                    UTILS                                   //
////////////////////////////////////////////////////////////////////////////////

long int	philo_atol(const char *nptr);
void		philo_info(t_info *info, char **av);
void		info_range(t_info info, int np);

////////////////////////////////////////////////////////////////////////////////
//                                   THREADS                                  //
////////////////////////////////////////////////////////////////////////////////

void		*philo_create(void *arg);
void		create_philos(t_philo *philo, t_info info, int np);
void		join_philos(t_philo *philo, int np);

#endif
