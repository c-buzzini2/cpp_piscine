/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:42:23 by cbuzzini          #+#    #+#             */
/*   Updated: 2025/11/21 16:36:40 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int    ft_add_contact()
{
    char    buff[250];
    
    std::cout << "First name:"
	<< std::endl;
    std::cin.getline(buff, 30);
    //CALL SET_INFO PARAMS F_NAME AND LINE
    //THEN, DO THE SAME FOR ALL PARAMETERS
    //CREATE FUNCTION THAT CHECKS IF THE INPUT IS EMPTY, AND THEN SET THE ENTIRE CONTACT TO NULL AND RETURNS 2, TO START THE PROMPT AGAIN
    //MAKE SURE THAT THAT RETURN 2 GOES BACK THE ENTIRE CHAIN
    //RUN THAT FUNCTION FOR EVERY NEW INPUT
}