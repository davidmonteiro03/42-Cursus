/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:25:17 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/19 20:43:40 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include "Brain.hpp"

class Animal
{
	protected:
		std::string	_type;
	public:
		Animal(void);
		Animal(std::string type);
		virtual	~Animal();
		Animal(const Animal &ref);
		Animal& operator=(const Animal &rhs);

		virtual void	makeSound(void) const;
		std::string		getType(void) const;
};

#endif
