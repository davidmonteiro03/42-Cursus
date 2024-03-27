/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:25:40 by dcaetano          #+#    #+#             */
/*   Updated: 2024/03/27 13:00:12 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP

# include "headers.hpp"

class Server
{
	private:
		std::pair<int, std::string> _info;
		int _server;
		struct sockaddr_in _servaddr;
		fd_set _fds, _events;
		int _nfds;
	public:
		Server(int argc, char **argv);
		Server(const Server& copy);
		Server& operator=(const Server& other);
		~Server();
		void ft_create(void);
		void ft_fail(void);
		void ft_close(void);
		class Usage : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class ServerError : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif
