/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:53:36 by cbuzzini          #+#    #+#             */
/*   Updated: 2025/11/24 15:24:54 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "PhoneBook.hpp"
#include <iostream>

class Contact
{
	public:
		void	ft_set_info(int info_type, std::string content);
		//Contact(void);
		//~Contact(void);
		//functions to add and search contacts
	
	private:
		std::string	_phone_nb;
		std::string	_f_name;
		std::string	_l_name;
		std::string	_nick;
		std::string	_secret;

};

#endif
