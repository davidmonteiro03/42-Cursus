/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 09:14:41 by dcaetano          #+#    #+#             */
/*   Updated: 2024/11/08 22:50:16 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/includes/Vector2.hpp"
#include "mandatory/includes/Graph.hpp"
#include <sstream>

int main(void)
{
	Graph g;
	while (!std::cin.eof())
	{
		system("clear");
		if (g.size() > 0)
			std::cout << g << std::endl
					  << std::endl;
		std::cout << "Point (x and y): ";
		std::string s_line;
		std::getline(std::cin, s_line);
		if (s_line.empty())
			continue;
		std::stringstream ss_line(s_line);
		float x, y;
		while (ss_line >> x >> y)
			g.addVector2(Vector2(x, y));
	}
	return 0;
}
