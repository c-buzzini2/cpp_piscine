/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 17:18:31 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/03/27 17:33:23 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <string>
#include <cstdlib>
#include <climits>
#include <cerrno>
#include "ScalarConverter.hpp"

input_type ScalarConverter::validate_number(std::string& input)
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
			return (FLOAT);
		else
		{
			std::cout << "invalid input\n";
			std::exit(1);		
		}
	}
	if (dot == true)
		return (DOUBLE);
	else
		return (INTEGER);
}

input_type ScalarConverter::detect_type(std::string &input)
{
	if (input.length() == 0)
	{
		std::cout << "invalid input\n";
		std::exit(1);		
	}
	std::cout << std::fixed << std::setprecision(1);
	if (input.length() == 1 && !std::isdigit(input.at(0)))
		return (CHAR);
	//CHECH INF NANF ETC
	else
		return (validate_number(input));
}

void ScalarConverter::convert(std::string input)
{
	input_type res;
	
	res = detect_type(input);
	switch (res)
	{
		case CHAR:
			str_to_char(input.at(0));
			break;

		case INTEGER:
			str_to_int(input);
			break;
			
		case FLOAT:
			str_to_float(input);
			break;

		case DOUBLE:
			str_to_double(input);
			break;
		
		default:
			break;
	}
}

//START HERE!!!!

//What is the smartest way to organize this? In every conversion in the future, I'll have to check the limits -> apparently, just for char
// How do I detect overflow in the conversions between number types?
void ScalarConverter::str_to_char(char first_char) //or just to_char? Do I want to call this from the number functions? In this case, I need the other check
// if (first_char < 0 || first_char > 127)
// 	std::cout << "char: impossible\n";
{
	if (first_char < 32 || first_char > 126)
		std::cout << "char: non-displayable\n";
	else
	{
		std::cout << "char: " << first_char << "\n";
	}
	std::cout << "int: " << static_cast<int>(first_char) << "\n";
	std::cout << "float: " << static_cast<float>(first_char) << "f\n";
	std::cout << "double: " << static_cast<double>(first_char) << "\n";
}

void ScalarConverter::str_to_int(std::string input)
{
	int nb;
	errno = 0;
	long val = std::strtol(input.c_str(), NULL, 10);
	if (errno == ERANGE || val > INT_MAX || val < INT_MIN)
	{
			std::cout << "invalid input\n";
			std::exit(1);	
	}
	nb = std::atoi(input.c_str());
	std::cout << "int: " << nb << "\n";
}

void ScalarConverter::str_to_float(std::string input)
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

void ScalarConverter::str_to_double(std::string input)
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