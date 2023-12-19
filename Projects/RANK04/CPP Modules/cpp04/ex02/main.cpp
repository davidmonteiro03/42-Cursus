/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:25:24 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/19 20:46:14 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int	main(void)
{
	const AAnimal* dog = new Dog();
	const AAnimal* cat = new Cat();

	delete cat;
	delete dog;

	const AAnimal* animals[4] = {
		new Cat(),
		new Dog(),
		new Dog(),
		new Cat()
	};
	for (int i = 0; i < 4; i++)
		animals[i]->makeSound();
	for (int i = 0; i < 4; i++)
		delete animals[i];
	return 0;
}
