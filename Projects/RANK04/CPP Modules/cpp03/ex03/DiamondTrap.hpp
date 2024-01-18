/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:50:42 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/18 21:10:23 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string _name;
	public:
		// Orthodox Canonical Form
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap& ref);
		DiamondTrap& operator=(const DiamondTrap& rhs);
		~DiamondTrap();

		// member functions
		void attack(const std::string& target);
		void whoAmI();
};

#endif
