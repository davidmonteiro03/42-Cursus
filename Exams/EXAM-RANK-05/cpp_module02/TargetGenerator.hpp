/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 17:35:20 by dcaetano          #+#    #+#             */
/*   Updated: 2024/02/04 17:35:20 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP

# include "ATarget.hpp"
# include <map>

class TargetGenerator
{
	private:
		std::map<std::string, ATarget*> _targets;
	public:
		TargetGenerator();
		~TargetGenerator();
		void learnTargetType(ATarget* target);
		void forgetTargetType(const std::string& target_type);
		ATarget* createTarget(const std::string& target_type);
};

#endif
