/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:17:34 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/01/16 17:45:57 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{	
	std::string str = "HI THIS IS BRAIN";
	std::string &stringREF = str;
	std::string *stringPTR = &str;
	
	std::cout << "Addr STR: " << &str
				<<std::endl;
	std::cout << "Addr PTR: " << stringPTR
				<<std::endl;
	std::cout << "Addr REF: " << &stringREF
				<<std::endl;
	
	std::cout << "Value STR: " << str
				<<std::endl;
	std::cout << "Value PTR: " << *stringPTR
				<<std::endl;
	std::cout << "Value REF: " << stringREF
				<<std::endl;
}