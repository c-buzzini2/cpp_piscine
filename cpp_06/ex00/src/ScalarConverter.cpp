/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 17:18:31 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/03/30 15:44:44 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <string>
#include <cstdlib>
#include <climits>
#include <cerrno>
#include "ScalarConverter.hpp"

void ScalarConverter::str_to_char(char first_char)
{
	if (first_char < 32 || first_char > 126)
		std::cout << "char: non-displayable\n";
	else
		std::cout << "char: " << first_char << "\n";
	std::cout << "int: " << static_cast<int>(first_char) << "\n";
	std::cout << "float: " << static_cast<float>(first_char) << "f\n";
	std::cout << "double: " << static_cast<double>(first_char) << "\n";
}

void ScalarConverter::str_to_int(std::string &input)
{
	int nb;
	
	nb = std::atoi(input.c_str());
	if (!IsInRange<char, int>(nb))
		std::cout << "char: impossible\n";
	std::cout << "int: " << nb << "\n";
	std::cout << "float: " << static_cast<float>(nb) << "f\n";
	std::cout << "double: " << static_cast<double>(nb) << "\n";
}

void ScalarConverter::str_to_float(std::string &input)
{
    float nb;
	
	errno = 0;
	nb = std::strtof(input.c_str(), NULL);
	if (errno != 0)
	{
		std::cerr << "invalid input\n";
		return;
	}
	if (!IsInRange<char, float>(nb))
		std::cout << "char: impossible\n";
	if (!IsInRange<int, float>(nb))
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " <<  static_cast<int>(nb) << "\n";
	std::cout << "float: " << nb << "f\n";
	std::cout << "double: " << static_cast<double>(nb) << "\n";
}

void ScalarConverter::str_to_double(std::string &input)
{
    double nb;
	
	errno = 0;
	nb = std::strtod(input.c_str(), NULL);
	if (errno != 0)
	{
		std::cerr << "invalid input\n";
		return;
	}
	if (!IsInRange<char, double>(nb))
		std::cout << "char: impossible\n";
		
	if (!IsInRange<int, double>(nb))
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " <<  static_cast<int>(nb) << "\n";
		
	if (!IsInRange<float, double>(nb))
		std::cout << "float: impossible\n";
	else
		std::cout << "float: " <<  static_cast<float>(nb) << "f\n";
	std::cout << "double: " << nb << "\n";
}

void ScalarConverter::pseudo_literals(std::string &input)
{
	std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";
	if (input == "nan" || input == "+inf" || input == "-inf")
	{
		float nb = strtof(input.c_str(), NULL);
		std::cout << "float: " <<  nb << "f\n";
		std::cout << "double: " <<  static_cast<double>(nb) << "\n";
	}
	else
	{
		double nb = strtod(input.c_str(), NULL);
		std::cout << "float: " <<  static_cast<float>(nb) << "f\n";
		std::cout << "double: " <<  nb << "\n";
	}
}
