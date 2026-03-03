/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 14:38:46 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/03/03 09:59:50 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class AForm
{
    public:
        AForm(void);
        AForm(std::string name, int sign_grade, int exec_grade);
        AForm(const AForm& src);
        virtual ~AForm(void);
        
        std::string getName(void) const;
        virtual std::string getTarget(void) const = 0;
        int         getGradeExec(void) const;
        int         getGradeSign(void) const;
        bool        getAlreadySigned(void) const;
        void        beSigned(Bureaucrat& brcrt);
        void        execute(Bureaucrat const & exctr) const;
        virtual void        action(void) const = 0;

    
        class GradeTooHighException : public std::exception
        {
            const char* what(void) const throw();
        };
        class GradeTooLowException : public std::exception
        {
            const char* what(void) const throw();
        };
        class FormNotSigned : public std::exception
        {
            const char* what(void) const throw();
        };
        
        private:
        const std::string   _name;
        const int           _grade_to_sign;
        const int           _grade_to_exec;
        bool                _already_signed;
        AForm& operator=(const AForm& src);
};

std::ostream& operator<<(std::ostream& os, const AForm & form);

#endif