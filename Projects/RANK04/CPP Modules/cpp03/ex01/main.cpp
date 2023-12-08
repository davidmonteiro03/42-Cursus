/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:59:02 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/08 13:13:33 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main( void )
{
	ScavTrap	scav("name");

	scav.attack("target");
	scav.beRepaired(10);
	scav.takeDamage(5);
	scav.guardGate();
	return (0);
}
