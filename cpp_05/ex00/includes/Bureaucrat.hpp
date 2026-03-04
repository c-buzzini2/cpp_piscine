/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 10:48:44 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/03/04 09:57:05 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# include <iostream>

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
        
        class GradeTooHighException : public std::exception
        {
            const char* what(void) const throw();
        };
        class GradeTooLowException : public std::exception
        {
            const char* what(void) const throw();
        };
        
    private:
        Bureaucrat& operator=(const Bureaucrat& src);
        const std::string   _name;
        int                 _grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat & brcrt);

#endif