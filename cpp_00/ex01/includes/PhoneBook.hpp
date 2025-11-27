/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:53:36 by cbuzzini          #+#    #+#             */
/*   Updated: 2025/11/27 17:38:57 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <sstream>
#include <string>
#include <iostream>
#include "Contact.hpp"
#include <iomanip>

//MAKE FUNCTIONS STATIC THAT DONT CHANGE ANYTHING
class PhoneBook
{
	public:
		int 		ft_add_contact(void);
		int			ft_search_contact(void);
		void		ft_display_list(void);
		void    	ft_print_contact(int i);
		std::string ft_truncate_field(const std::string &field);
		
	private:
		Contact		_contacts[8];
		static int	_total_contacts;
};

#endif