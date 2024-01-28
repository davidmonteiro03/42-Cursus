/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 11:41:34 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/28 12:07:26 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>

template<typename T>
void iter(T* array, size_t length, void (*f)(T&))
{
	for (size_t i = 0; i < length; i++)
		f(array[i]);
}

#endif
