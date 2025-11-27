/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:53:36 by cbuzzini          #+#    #+#             */
/*   Updated: 2025/11/27 18:22:02 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "PhoneBook.hpp"
#include <iostream>
#include <cctype>

class Contact
{
	public:
		int			ft_create_contact(void);
		std::string	ft_get_info(int info_type) const;
		
	private:
		int			ft_set_info(int info_type, std::string content);
		bool		ft_input_is_valid(std::string input) const;
		bool		ft_phone_is_valid(std::string input) const;

		std::string	_f_name;
		std::string	_l_name;
		std::string	_nick;
		std::string	_phone_nb;
		std::string	_secret;
};

#endif
