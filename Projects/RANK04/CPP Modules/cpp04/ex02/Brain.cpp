/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 20:06:24 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/19 20:21:14 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain created" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destroyed" << std::endl;
}

Brain::Brain(const Brain &ref)
{
	*this = ref;
}

Brain& Brain::operator=(const Brain &rhs)
{
	std::cout << "Brain copied" << std::endl;
	if (this != &rhs)
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = rhs._ideas[i];
	return (*this);
}
