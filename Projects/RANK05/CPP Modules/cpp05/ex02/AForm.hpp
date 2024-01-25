/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:39:09 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/25 08:29:53 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool _status;
		const int _signGrade;
		const int _execGrade;
	public:
		AForm();
		AForm(const std::string name, const int signGrade, const int execGrade);
		AForm(const AForm& copy);
		AForm& operator=(const AForm& other);
		virtual ~AForm();
		const std::string getName(void) const;
		bool getStatus(void) const;
		int getSignGrade(void) const;
		int getExecGrade(void) const;
		virtual void execute(Bureaucrat const & executor) const = 0;
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
		class UnsignedFormException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		void beSigned(Bureaucrat& bc);
};

std::ostream& operator<<(std::ostream& o, const AForm& form);

#endif
