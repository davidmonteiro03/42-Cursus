/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:50:55 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/30 17:02:27 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

typedef pthread_t		t_th;
typedef pthread_mutex_t	t_mt;
struct					s_dt;

typedef struct s_ph
{
	int			id;
	t_th		th;
	t_mt		*lf;
	t_mt		*rf;
	struct s_dt	*dt;
	struct s_ph	*nt;
}t_ph;

typedef struct s_dt
{
	int		np;
	int		td;
	int		te;
	int		ts;
	int		ne;
	t_ph	*ph;
	t_mt	*fk;
}t_dt;

// chk
long	ph_num(const char *s);
int		ph_chk(int i, char **v);

// dt utils
int		ph_din(t_dt **dt, char **v);

// ph utils
int		ph_pin(t_dt **dt, int i);
void	ph_clr(t_dt **dt, int i);

// run
void	*ph_th(void *ag);
void	ph_run(t_dt *dt);

// uts
long	ph_gtm(void);

#endif
