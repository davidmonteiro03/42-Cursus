/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:50:55 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/24 14:10:27 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* HEADERS */
# include <pthread.h> //	pthread_create, pthread_detach, pthread_join,
//							pthread_mutex_init, pthread_mutex_destroy,
//							pthread_mutex_lock, pthread_mutex_unlock
# include <unistd.h> //		usleep
# include <stdio.h> //		printf
# include <stdlib.h> //		malloc, free, exit
# include <sys/time.h> //	gettimeofday
# include <stdbool.h> //	bool

/* ERROR STRINGS */
# define ERR_ARG "Wrong number of arguments"
# define ERR_INV "Invalid arguments"
# define ERR_RNG "Invalid range"
# define ERR_IIN "Initialization failed"

/* PHILO STATUS STRINGS */
# define FRK "has taken a fork 🍴"
# define EAT "is eating 🍝"
# define THK "is thinking 💭"
# define SLP "is sleeping 💤"
# define DIE "died 💀"

/* TYPEDEFS */
typedef pthread_mutex_t	t_mt;
typedef pthread_t		t_th;

/* ************************************************************************** */
/*                                   STRUCTS                                  */
/* ************************************************************************** */

struct					s_in;

/* PHILO STRUCT */
typedef struct s_ph
{
	int				id;
	struct s_in		*in;
}t_ph;

/* DATA STRUCT */
typedef struct s_dt
{
	int	np;
	int	td;
	int	te;
	int	ts;
	int	ne;
}t_dt;

/* INPUT STRUCT */
typedef struct s_in
{
	t_dt	*dt;
	t_ph	*ph;
}t_in;

/* ************************************************************************** */
/*                                    CLEAN                                   */
/* ************************************************************************** */

/* clean data */
int		ph_clr(t_in *in, int st);

/* ************************************************************************** */
/*                                    ERROR                                   */
/* ************************************************************************** */

/* print error */
int		ph_err(char *e);

/* ************************************************************************** */
/*                                    INIT                                    */
/* ************************************************************************** */

/* init philo */
t_ph	*ph_iph(t_in *in);

/* init data */
t_dt	*ph_idt(char **v);

/* init input */
t_in	*ph_iin(char **v);

/* ************************************************************************** */
/*                                   PARSER                                   */
/* ************************************************************************** */

/* convert string to long */
long	ph_num(const char *s);

/* check if all the arguments are numbers */
int		ph_inv(char **v);

/* check if number is in range */
int		ph_rng(char **v);

#endif
