/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 10:48:44 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/03/02 10:21:59 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# include <iostream>

class Form;

class Bureaucrat
{
    public:
        Bureaucrat(void);
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat& src);
        ~Bureaucrat(void);
        
        std::string getName(void) const;
        int         getGrade(void) const;
        void        incrementGrade(void);
        void        decrementGrade(void);
        void        signForm(Form &form);
        
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
        int                 _grade;
        Bureaucrat& operator=(const Bureaucrat& src);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat & brcrt);

#endif