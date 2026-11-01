/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 14:54:29 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/11/01 12:38:02 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <string>
#include <cctype>
#include <sstream>
#include <exception>
#include <ctime>
#include <algorithm>

BitcoinExchange::BitcoinExchange(void)
{
}

BitcoinExchange::BitcoinExchange(const char* db_file)
{
	parse_file(db_file, true);
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

void BitcoinExchange::parse_file(const char* file, bool file_is_db)
{
	std::ifstream	file_stream(file);

	if (!file_stream.is_open())
	{
    	throw (std::runtime_error(std::string("Failed to open " + static_cast<std::string>(file) + ": ")
		+ std::strerror(errno)));
	}
	read_file(file_stream, file_is_db);
}

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
		double ret = validate_value(value_string, error_msg, file_is_db);
		if (file_is_db && ret != -1)
			this->database.insert(make_pair(date, ret));
		else if (!file_is_db && ret != -1)
			convert_and_print_value(date, ret);
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

	if (date_string < "2009-01-02")
		invalid_date = true;
	else if (!(ss >> year))
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
	else if (!date_exists(year, month, day))
		invalid_date = true;
	else if (!file_is_db)
		std::cout << date_string << " => ";
	if (invalid_date)
		std::cout << error_msg << "invalid date (" << date_string << ")\n";
	return (invalid_date);
}

bool BitcoinExchange::date_exists(int year, int month, int day)
{
	bool leap_year = false;
	
	if (month == 2)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
				leap_year = true;
		}
		else if (year % 4 == 0)
			leap_year = true;
		if ((leap_year && day > 29) || ((!leap_year) && day > 28))
			return (false);
	}
	else
	{
		int total_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

		if (day > total_days[month - 1])
			return (false);
	}
	std::time_t now = std::time(NULL);
	std::tm* today = std::localtime(&now);

	if (today == NULL)
		return (false);

	int curr_year = today->tm_year + 1900;
	int curr_month = today->tm_mon + 1;
	int curr_day = today->tm_mday;

	if (year > curr_year)
		return (false);
	if (year == curr_year && month > curr_month)
		return (false);
	if (year == curr_year && month == curr_month && day > curr_day)
		return (false);
	return (true);
}

double BitcoinExchange::validate_value(std::string value_string, std::string error_msg, bool file_is_db)
{
	double				value_double;
	std::istringstream	ss(value_string);

	if (!(ss >> value_double) || value_double > std::numeric_limits<int>::max())
		std::cout << error_msg << "Invalid numeric value: " << value_string << std::endl;
	else if (!ss.eof())
    	std::cout << error_msg << "Unexpected characters: " << value_string << std::endl;
	else if (value_double < 0)
    	std::cout << error_msg << "Negative value: " << value_string << std::endl;
	else if (!file_is_db)
	{	
		std::cout << value_string << " = ";
		return (value_double);
	}
	else if (file_is_db)
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

void BitcoinExchange::calculate(char* input_file)
{
	parse_file(input_file, false);
}

void BitcoinExchange::convert_and_print_value(std::string date_string, double bitcoins)
{
	double	rate = 0;
	std::map<std::string, double>::iterator it = database.upper_bound(date_string);

	if (it != database.begin())
	{
		--it;
		rate = it->second;
	}
	if (rate != 0 && bitcoins > std::numeric_limits<double>::max() / rate)
        std::cout << "Error: number is too large\n";
	else
		std::cout << std::fixed << std::setprecision(2) << (bitcoins * rate) << "\n";
}
