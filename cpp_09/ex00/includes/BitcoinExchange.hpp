/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 11:36:19 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/11/01 09:48:16 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <map>
#include <iostream>
#include <fstream>

class BitcoinExchange
{
    private:
        std::map<std::string, double>   database;
        //std::map<std::string, double>   input;
		
		BitcoinExchange(void);
		void		parse_database(const char* db_file);
		std::string trim_spaces(const std::string& str);
		void		read_file(std::ifstream& file_stream, bool file_is_db);
		double		validate_and_print_value(std::string value_string, std::string error_msg, bool file_is_db);
		bool		validate_and_print_date(std::string date_string, std::string error_msg, bool file_is_db);
		bool		date_exists(int year, int month, int day);

	public:
		BitcoinExchange(const char* db_file);
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange &operator=(const BitcoinExchange &src);
		~BitcoinExchange(void);
		void	calculate(char* input_file);
};
