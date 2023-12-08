/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:04:45 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/08 15:34:46 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	private:
		std::string	_type;
	public:
		WrongCat();
		WrongCat(WrongCat &ref);
		WrongCat& operator=(WrongCat const &ref);
		~WrongCat();

		void	makeSound() const;
};

#endif
