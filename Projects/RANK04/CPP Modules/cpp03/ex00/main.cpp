/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:59:02 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/08 11:27:39 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	John("John");
	ClapTrap	Doe("Doe");
	ClapTrap	ClapTrap3(John);

	John.beRepaired(10);
	Doe.beRepaired(10);
	John.attack("Doe");
	Doe.takeDamage(5);
	Doe.attack("John");
	John.takeDamage(5);
	John.attack("Doe");
	Doe.takeDamage(5);
	return (0);
}
