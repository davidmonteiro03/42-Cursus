/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:25:40 by dcaetano          #+#    #+#             */
/*   Updated: 2024/03/27 11:44:21 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP

# include "headers.hpp"

class Server
{
	private:
		std::pair<int, std::string> _info;
	public:
		Server(int argc, char **argv);
		Server(const Server& copy);
		Server& operator=(const Server& other);
		~Server();
		void execute(void);
		class Usage : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif
