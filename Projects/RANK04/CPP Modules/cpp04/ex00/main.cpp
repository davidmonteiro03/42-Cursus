/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:59:02 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/08 15:37:31 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main( void )
{
	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << std::endl;
	std::cout << "Dog->getType [" << dog->getType() << "] " << std::endl;
	std::cout << "Cat->getType [" << cat->getType() << "] " << std::endl;
	cat->makeSound();
	dog->makeSound();
	animal->makeSound();

	std::cout << std::endl;
	const WrongAnimal* wrong_animal = new WrongAnimal();
	const WrongAnimal* wrong_cat = new WrongCat();

	std::cout << std::endl;
	wrong_cat->makeSound();
	wrong_animal->makeSound();

	std::cout << std::endl;
	delete animal;
	delete dog;
	delete cat;
	delete wrong_cat;
	delete wrong_animal;
	return (0);
}
