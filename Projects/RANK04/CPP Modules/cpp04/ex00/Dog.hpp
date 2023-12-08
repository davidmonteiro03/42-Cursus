/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:04:45 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/08 15:49:03 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
	private:
		std::string	type;
	public:
		Dog();
		Dog(Dog &ref);
		Dog& operator=(Dog const &ref);
		~Dog();

		std::string	getType(void) const;
		void	makeSound() const;
};

#endif
