/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 14:38:46 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/03/02 10:01:11 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
    public:
        Form(void);
        Form(std::string name, int sign_grade, int exec_grade);
        Form(const Form& src);
        ~Form(void);
        
        std::string getName(void) const;
        int         getGradeExec(void) const;
        int         getGradeSign(void) const;
        bool        getAlreadySigned(void) const;
        void        beSigned(Bureaucrat& brcrt);
    
        class GradeTooHighException : public std::exception
        {
            const char* what(void) const throw();
        };
        class GradeTooLowException : public std::exception
        {
            const char* what(void) const throw();
        };
        
        private:
        const std::string   _name;
        const int           _grade_to_sign;
        const int           _grade_to_exec;
        bool                _already_signed;
        Form& operator=(const Form& src);
};

std::ostream& operator<<(std::ostream& os, const Form & form);

#endif