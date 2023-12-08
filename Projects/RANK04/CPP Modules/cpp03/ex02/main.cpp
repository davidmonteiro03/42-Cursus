/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:59:02 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/08 14:08:51 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main( void )
{
	FragTrap	frag("name");

	frag.attack("target");
	frag.beRepaired(10);
	frag.takeDamage(5);
	frag.highFivesGuys();
	return (0);
}
