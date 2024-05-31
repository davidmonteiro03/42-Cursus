/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:15:13 by dcaetano          #+#    #+#             */
/*   Updated: 2024/05/23 11:02:51 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_irc.hpp"

Server *server = NULL;
char hostname[256], *ip;

void signal_handler(int sig)
{
	if (sig == SIGINT)
	{
		if (server != NULL)
			delete server;
		logs("server", LOG_SHUTDOWN);
		exit(EXIT_SUCCESS);
	}
}

int main(int argc, char **argv)
{
	signal(SIGINT, signal_handler);
	signal(SIGPIPE, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	try
	{
		server = new Server(argc, argv);
		server->getInfo();
		server->execute();
		if (server != NULL)
			delete server;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
	return ((void)argc, (void)argv, EXIT_SUCCESS);
}
