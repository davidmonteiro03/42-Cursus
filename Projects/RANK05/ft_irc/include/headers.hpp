/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:22:54 by dcaetano          #+#    #+#             */
/*   Updated: 2024/03/27 12:37:33 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERS_HPP
# define HEADERS_HPP

extern "C"
{
	#include <stdio.h>
	#include <unistd.h>
	#include <strings.h>
	#include <sys/socket.h>
	#include <sys/select.h>
	#include <netdb.h>
}

# include <iostream>
# include <cstdlib>
# include <stdexcept>
# include <cstring>

# define PASSWORD_REQUEST "Type password: "

#endif
