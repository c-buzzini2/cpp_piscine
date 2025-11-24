/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 15:15:53 by cbuzzini          #+#    #+#             */
/*   Updated: 2025/11/24 15:42:41 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

void	Contact::ft_set_info(int info_type, std::string content)
{
	//CREATE FUNCTION THAT CHECKS IF THE INPUT IS EMPTY, 
	//AND THEN SET THE ENTIRE CONTACT TO NULL AND RETURNS 2
	//TO START THE PROMPT AGAIN

    if (info_type == 0)
        this->_f_name = content;
    else if (info_type == 1)
        this->_l_name = content;
	else if (info_type == 2)
        this->_nick = content;
    else if (info_type == 3)
        this->_secret = content;
    else if (info_type == 4)
        this->_phone_nb = content; //CHECK IF IT'S DIGITS AND +
}
