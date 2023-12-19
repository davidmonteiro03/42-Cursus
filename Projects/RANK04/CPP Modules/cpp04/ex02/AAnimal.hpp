/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:25:17 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/19 20:44:30 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include "Brain.hpp"

class AAnimal
{
	protected:
		std::string	_type;
	public:
		AAnimal(void);
		AAnimal(std::string type);
		virtual	~AAnimal();
		AAnimal(const AAnimal &ref);
		AAnimal& operator=(const AAnimal &rhs);

		virtual void	makeSound(void) const = 0;
		std::string		getType(void) const;
};

#endif
