/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:25:17 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/19 19:52:17 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
	protected:
		std::string	_type;
	public:
		WrongAnimal(void);
		WrongAnimal(std::string type);
		virtual	~WrongAnimal();
		WrongAnimal(const WrongAnimal &ref);
		WrongAnimal& operator=(const WrongAnimal &rhs);

		virtual void	makeSound(void) const;
		std::string		getType(void) const;
};

#endif
