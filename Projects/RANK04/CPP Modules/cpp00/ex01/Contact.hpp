/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:18:39 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/04 18:57:23 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	phone_number;
		std::string	nickname;
		std::string	darkest_secret;
	public:
		Contact(void);
		~Contact(void);
		std::string	get_first_name(void) const;
		std::string	get_last_name(void) const;
		std::string	get_phone_number(void) const;
		std::string	get_nickname(void) const;
		std::string	get_darkest_secret(void) const;
		void		set_first_name(std::string str);
		void		set_last_name(std::string str);
		void		set_phone_number(std::string str);
		void		set_nickname(std::string str);
		void		set_darkest_secret(std::string str);
};

#endif
