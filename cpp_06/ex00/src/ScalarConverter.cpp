/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 17:18:31 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/03/27 12:18:26 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <string>
#include <cstdlib>
#include "ScalarConverter.hpp"

std::string ScalarConverter::validate_number(std::string& input)
{
	std::string::size_type len = input.length();
	std::string::size_type j = 0;
	bool dot = false;

	if (input.at(0) == '-' || std::isdigit(static_cast<unsigned char>(input.at(0))))
		j++;
	else
	{
		std::cout << "invalid input\n";
		std::exit(1);
	}
	for (std::string::size_type i = j; i < len; i++)
	{
		if (std::isdigit(static_cast<unsigned char>(input.at(i))))
			continue;
		else if (input.at(i) == '.')
		{
			if (dot == true || i == len - 1)
			{
				std::cout << "invalid input\n";
				std::exit(1);
			}
			dot = true;
			continue;
		}
		else if (i == len - 1 && input.at(i) == 'f' && input.at(i - 1) != '.' && dot == true)
			return ("float");
		else
		{
			std::cout << "invalid input\n";
			std::exit(1);		
		}
	}
	if (dot == true)
		return ("double");
	else
		return ("integer");
}

void ScalarConverter::detect_type(std::string &input)
{
	if (input.length() == 0)
		return;
	std::cout << std::fixed << std::setprecision(1);
	if (input.length() == 1 && !std::isdigit(input.at(0)))
		to_char(input.at(0));
	//CHECH INF NANF ETC
	else
	{
		std::string input_type = validate_number(input);
		std::cout << input_type << "\n"; //DELETE
	}
	// to_int(input);
	// to_float(input);
	// to_double(input);
}

void ScalarConverter::convert(std::string input)
{
	detect_type(input);
	//to_char(input);
	//to_int(input);
	//to_float(input);
	//to_double(input);
}

void ScalarConverter::to_char(unsigned int first_char)
{
	if (first_char < 32 || first_char > 126)
		std::cout << "non-displayable\n";
	else
	{
		std::cout << "char: " << static_cast<char>(first_char) << "\n";
		std::cout << "int: " << static_cast<int>(first_char) << "\n";
		std::cout << "float: " << static_cast<float>(first_char) << "f\n";
		std::cout << "double: " << static_cast<double>(first_char) << "\n";
	}
}

void ScalarConverter::to_int(std::string input)
{
    int nb = 0;
	
	// try
	// {
	// 	nb = std::stoi(input);
	// }
	// catch(const std::invalid_argument& e)
	// {
	// 	std::cerr << "Not a number\n";
	// 	return;
	// }
	// catch(const std::out_of_range& e)
	// {
	// 	std::cerr << "Number out of range\n";
	// 	return;
	// }
	std::cout << "int: " << nb << "\n";
}

void ScalarConverter::to_float(std::string input)
{
    float nb = 0;
	
	// try
	// {
	// 	nb = std::stof(input);
	// }
	// catch(const std::invalid_argument& e)
	// {
	// 	std::cerr << "Not a number\n";
	// 	return;
	// }
	// catch(const std::out_of_range& e)
	// {
	// 	std::cerr << "Number out of range\n";
	// 	return;
	// }
	std::cout << "float: " << nb << "\n";
}

void ScalarConverter::to_double(std::string input)
{
    double nb = 0;
	
	// try
	// {
	// 	nb = std::stod(input);
	// }
	// catch(const std::invalid_argument& e)
	// {
	// 	std::cerr << "Not a number\n";
	// 	return;
	// }
	// catch(const std::out_of_range& e)
	// {
	// 	std::cerr << "Number out of range\n";
	// 	return;
	// }
	std::cout << "double: " << nb << "\n";
}