/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:04:45 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/08 15:48:33 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
	private:
		std::string	type;
	public:
		Cat();
		Cat(Cat &ref);
		Cat& operator=(Cat const &ref);
		~Cat();

		std::string	getType(void) const;
		void	makeSound() const;
};

#endif
