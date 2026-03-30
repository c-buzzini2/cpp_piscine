/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 17:18:31 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/03/30 14:32:25 by cbuzzini         ###   ########.fr       */
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
	{
		if (valid_int(input))
			return (INTEGER);
		else
		{
			std::cout << "invalid input\n";
			std::exit(1);		
		}
	}
}

bool ScalarConverter::valid_int(std::string &input)
{
	long val = std::strtol(input.c_str(), NULL, 10);
	
	if (errno == ERANGE || val > INT_MAX || val < INT_MIN)
		return (false);
	return (true);
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
	
	try
	{
		nb = std::strtof(input.c_str(), NULL);
	}
	catch(const std::exception& e)
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
	
	try
	{
		nb = std::strtod(input.c_str(), NULL);
	}
	catch(const std::exception& e)
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
		std::cout << "float: " <<  static_cast<float>(nb) << "\n";
	std::cout << "float: " << nb << "f\n";
}
