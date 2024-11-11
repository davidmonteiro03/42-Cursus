/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:29:10 by dcaetano          #+#    #+#             */
/*   Updated: 2024/11/08 09:05:33 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/includes/Account.hpp"
#include "mandatory/includes/Bank.hpp"

int main()
{
	Account accountA(0, 100);
	Account accountB(1, 100);

	Bank bank(999);
	bank.addAccount(&accountA);
	bank.addAccount(&accountB);

	bank.decreaseLiquidity(200);
	bank.increaseAccountValue(&accountA, 400);

	std::cout << "Account : " << std::endl;
	std::cout << accountA << std::endl;
	std::cout << accountB << std::endl;

	std::cout << " ----- " << std::endl;

	std::cout << "Bank : " << std::endl;
	std::cout << bank << std::endl;

	return (0);
}
