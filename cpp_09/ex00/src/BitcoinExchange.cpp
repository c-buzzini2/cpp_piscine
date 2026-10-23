/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 14:54:29 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/10/23 16:13:57 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <string>
#include <cctype>
#include <sstream>

BitcoinExchange::BitcoinExchange(void)
{
}

BitcoinExchange::BitcoinExchange(const char* db_file)
{
	parse_database(db_file);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	*this = src;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
	if (this != &src)
	{
		this->database = src.database;
		this->input = src.input;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{
}

void BitcoinExchange::parse_database(const char* db_file)
{
	std::ifstream	db_stream(db_file);

	read_file(db_stream, true);
}

void BitcoinExchange::read_file(std::ifstream& file_stream, bool file_is_db)
{
	std::string		line;
	std::string		separator;

	if (file_is_db)
		separator = ",";
	else
		separator = " | ";

	while (getline(file_stream, line))
	{
		//std::istringstream	ss(line);
		//std::string			date;
		//std::string			value_string;
		//double				value_double;
		std::cout << line << "\n";
	}
}



std::string BitcoinExchange::trim_spaces(const std::string& str)
{
    std::string::size_type start = 0;
    std::string::size_type end = str.size();

    while (start < end && std::isspace(static_cast<unsigned char>(str[start])))
        ++start;

    while (end > start && std::isspace(static_cast<unsigned char>(str[end - 1])))
        --end;

    return (str.substr(start, end - start));
}