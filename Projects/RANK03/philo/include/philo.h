/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:50:55 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/27 13:16:28 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_dt
{
	int	np;
	int	td;
	int	te;
	int	ts;
	int	ne;
}t_dt;

typedef struct s_ph
{
	int			id;
	pthread_t	th;
	t_dt		*dt;
	struct s_ph	*nt;
}t_ph;

// chk
long	ph_num(const char *s);
int		ph_chk(int i, char **v);

// dt utils
int		dt_iin(t_dt **dt, char **v);

// ph utils
int		ph_iin(t_ph **ph, t_dt *dt, int i);
void	ph_clr(t_ph **ph);

#endif
