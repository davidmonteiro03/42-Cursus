/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:51:12 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/08 15:08:23 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	protected:
		std::string	_type;
	public:
		Animal();
		Animal(Animal &ref);
		Animal& operator=(Animal const &ref);
		virtual ~Animal();

		virtual std::string	getType(void) const;
		virtual void	makeSound() const;
};

#endif
