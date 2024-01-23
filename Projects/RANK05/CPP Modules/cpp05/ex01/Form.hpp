/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:39:09 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/23 14:17:51 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _status;
		const int _signGrade;
		const int _execGrade;
	public:
		Form();
		Form(const std::string name, const int signGrade, const int execGrade);
		Form(const Form& copy);
		Form& operator=(const Form& other);
		~Form();
		const std::string getName(void) const;
		bool getStatus(void) const;
		int getSignGrade(void) const;
		int getExecGrade(void) const;
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class AlreadySignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		void beSigned(Bureaucrat& bc);
};

std::ostream& operator<<(std::ostream& o, const Form& form);

#endif
