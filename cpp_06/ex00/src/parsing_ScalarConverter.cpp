/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_ScalarConverter.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 17:18:31 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/03/30 15:16:38 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <string>
#include <cstdlib>
#include <climits>
#include <cerrno>
#include <cmath>
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
	if (input == "nan" || input == "nanf" || input == "+inf" || input == "+inff"
		|| input == "-inf" || input == "-inff") 
	{
		pseudo_literals(input);
		exit(0);
	} 
	if (input.length() == 1 && !std::isdigit(input.at(0)))
		return (CHAR);
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
