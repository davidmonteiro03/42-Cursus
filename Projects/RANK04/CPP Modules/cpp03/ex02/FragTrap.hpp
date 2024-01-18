/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:03:50 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/18 21:03:59 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		// Orthodox Canonical Form
		FragTrap(std::string name);
		FragTrap(const FragTrap& ref);
		FragTrap& operator=(const FragTrap& rhs);
		~FragTrap();

		// member functions
		void attack(const std::string& target);
		void highFivesGuys(void);
};

#endif
