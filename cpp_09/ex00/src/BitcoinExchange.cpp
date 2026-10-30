/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 14:54:29 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/10/30 15:16:36 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <string>
#include <cctype>
#include <sstream>
#include <exception>

BitcoinExchange::BitcoinExchange(void)
{
}

BitcoinExchange::BitcoinExchange(const char* db_file)
{
	parse_database(db_file);
	//DEBUG!!!
	std::map<std::string, double>::iterator it;

	for (it = database.begin(); it != database.end(); ++it) {
		std::cout << it->first << " " << it->second << std::endl;
	}
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
		//this->input = src.input;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{
}

void BitcoinExchange::parse_database(const char* db_file)
{
	std::ifstream	db_stream(db_file);

	if (!db_stream.is_open())
	{
    	throw (std::runtime_error(std::string("Failed to open file: ")
		+ std::strerror(errno)));
	}
	read_file(db_stream, true);
}

//START HERE! I HAVE TO THINK OF A WAY OF DEALING WITH BAD DATABASE
//VS BAD INPUT
//IN THEORY, FOR BAD INPUT, I PRINT THE PROBLEM AND THEN CONTINUE PRINTING
//BUT FOR BAD DATABASE, I'D RATHER THROW AN EXCEPTION
//DATES ARE CONVERTED FOR VALIDATION, BUT SAVED AS STRING

void BitcoinExchange::read_file(std::ifstream& file_stream, bool file_is_db)
{
	std::string	line;
	char		separator;
	std::string	first_line;
	std::string	error_msg;

	if (file_is_db)
	{
		separator = ',';
		first_line = "date,exchange_rate";
		error_msg = "Database warning:\n";
	}
	else
	{
		separator = '|';
		first_line = "date | value";
		error_msg = "Input error! ";
	}
	std::getline(file_stream, line);
	if (line != first_line)
	{	
		throw (std::runtime_error("first line should be 'date,exchange_rate' for database "
								"and 'date | value' for input file"));
	}
	while (std::getline(file_stream, line))
	{		
		std::istringstream	ss(line);
		std::string			date;
		std::string			value_string;

		std::getline(ss, date, separator);
		std::getline(ss, value_string, separator);

		date = trim_spaces(date);
		value_string = trim_spaces(value_string);

		if (!ss.eof())
		{
    		std::cout << error_msg << "Line out of format: " << line << std::endl;
			continue;
		}
	
		if (validate_and_print_date(date, error_msg, file_is_db) == 1)
			continue;
		double ret = validate_and_print_value(value_string, error_msg, file_is_db);
		if (file_is_db && ret != -1)
			this->database.insert(make_pair(date, ret));
		else if (!file_is_db)
			//convert (multiply and check limits)
			//std::cout << std::fixed << std::setprecision(2) << value_double << "\n";
			std::cout << "CONVERT and print!!\n";
	}
}

bool BitcoinExchange::validate_and_print_date(std::string date_string, std::string error_msg, bool file_is_db)
{
	int					day;
	int					month;
	int					year;
	char				dash1 = 0;
	char				dash2 = 0;
	std::istringstream	ss(date_string);
	bool				invalid_date = false;

	//validate date in the future, before 2009, feb + leap year, 30/31 days
	if (!(ss >> year) || year < 2009)
		invalid_date = true;
	else if (!(ss >> dash1) || dash1 != '-')
		invalid_date = true;
	else if (!(ss >> month) || month < 1 || month > 12)
		invalid_date = true;
	else if (!(ss >> dash2) || dash2 != '-')
		invalid_date = true;
	else if (!(ss >> day) || day < 1 || day > 31)
		invalid_date = true;
	else if (!ss.eof())
		invalid_date = true;
	else if (!file_is_db)
		std::cout << date_string << " => ";
	if (invalid_date)
		std::cout << error_msg << "invalid date (" << date_string << ")\n";
	return (invalid_date);
}

double BitcoinExchange::validate_and_print_value(std::string value_string, std::string error_msg, bool file_is_db)
{
	double				value_double;
	std::istringstream	ss(value_string);

	if (!(ss >> value_double))
		std::cout << error_msg << "Invalid numeric value: " << value_string << std::endl;
	else if (!ss.eof())
    	std::cout << error_msg << "Unexpected characters: " << value_string << std::endl;
	else if (value_double < 0)
    	std::cout << error_msg << "Negative value: " << value_string << std::endl;
	else if (!file_is_db)
		std::cout << value_string << " = ";
	else
		return (value_double);
	return (-1);
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