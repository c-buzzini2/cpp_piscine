/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 17:13:40 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/03/27 17:23:48 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

# include <iostream>

enum input_type
{
    CHAR,
    INTEGER,
    FLOAT,
    DOUBLE
};

class ScalarConverter
{
    private:
        ScalarConverter(void);
        ScalarConverter(const ScalarConverter& src);
        ScalarConverter& operator=(const ScalarConverter& src);
        ~ScalarConverter(void);
        static void str_to_char(char first_char);
        static void str_to_int(std::string input);
        static void str_to_float(std::string input);
        static void str_to_double(std::string input);
        static input_type detect_type(std::string &input);
        static input_type validate_number(std::string& input);


    public:
		static void convert(std::string input);
};

#endif