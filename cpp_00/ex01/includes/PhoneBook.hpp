/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:53:36 by cbuzzini          #+#    #+#             */
/*   Updated: 2025/11/27 18:00:52 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <sstream>
#include <string>
#include <iostream>
#include "Contact.hpp"
#include <iomanip>

class PhoneBook
{
	public:
		int 		ft_add_contact(void);
		int			ft_search_contact(void) const;
		void		ft_display_list(void) const;
		void    	ft_print_contact(int i) const;
		std::string ft_truncate_field(const std::string &field) const;
		
	private:
		Contact		_contacts[8];
		static int	_total_contacts;
};

#endif