/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 22:14:43 by dcaetano          #+#    #+#             */
/*   Updated: 2024/02/02 22:14:52 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASPELL_HPP
# define ASPELL_HPP

# include <iostream>
# include "ATarget.hpp"

class ATarget;

class ASpell
{
	protected:
		std::string _name;
		std::string _effects;
	public:
		ASpell(std::string name, std::string effects);
		virtual ~ASpell();
		std::string getName(void) const;
		std::string getEffects(void) const;
		virtual ASpell* clone() const = 0;
		void launch(const ATarget& target) const;
};

#endif
