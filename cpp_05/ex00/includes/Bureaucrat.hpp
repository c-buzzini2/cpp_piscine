/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 10:48:44 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/02/27 13:47:08 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# include <iostream>

//IMPLEMENT OPERATOR << AND INCREMENT/DECREMENT

class Bureaucrat
{
    public:
        Bureaucrat(void);
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat& src);
        Bureaucrat& operator=(const Bureaucrat& src);
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
        const std::string   _name;
        int                 _grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat & brcrt);

#endif