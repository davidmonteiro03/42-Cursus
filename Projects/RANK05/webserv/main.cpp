/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 12:12:20 by dcaetano          #+#    #+#             */
/*   Updated: 2024/03/24 15:09:00 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

struct Server
{
	std::string name;
	std::vector<Server> children;
};

int main(void)
{
	Server server;
	server.name = "server";
	return 0;
}
