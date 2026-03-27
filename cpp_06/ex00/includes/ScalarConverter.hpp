/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 17:13:40 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/03/27 12:04:44 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

# include <iostream>

class ScalarConverter
{
    private:
        ScalarConverter(void);
        ScalarConverter(const ScalarConverter& src);
        ScalarConverter& operator=(const ScalarConverter& src);
        ~ScalarConverter(void);
        static void to_char(unsigned int first_char);
        static void to_int(std::string input);
        static void to_float(std::string input);
        static void to_double(std::string input);
        static void detect_type(std::string &input);
        static std::string validate_number(std::string& input);


    public:
		static void convert(std::string input);
};

#endif