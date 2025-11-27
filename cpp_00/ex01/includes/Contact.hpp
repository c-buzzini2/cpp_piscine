/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:53:36 by cbuzzini          #+#    #+#             */
/*   Updated: 2025/11/27 17:40:48 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "PhoneBook.hpp"
#include <iostream>
#include <cctype>

class Contact //MAKE FUNCTIONS STATIC THAT DONT CHANGE ANYTHING
{
	public:
		int		ft_create_contact(void);
		std::string	ft_get_info(int info_type);
		
	private:
		int		ft_set_info(int info_type, std::string content);
		bool		ft_input_is_valid(std::string input);
		std::string	_f_name;
		std::string	_l_name;
		std::string	_nick;
		std::string	_secret;
		std::string	_phone_nb;
};

#endif
