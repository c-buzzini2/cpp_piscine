/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 13:04:10 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/03/04 13:57:05 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

# include "AForm.hpp"

class Intern
{
    public:
        Intern(void);
        Intern(const Intern& src);
        Intern& operator=(const Intern& src);
        ~Intern(void);

        AForm *makeForm(std::string name, std::string target);

    private:
        static AForm *makeShrub(std::string target);
        static AForm *makeRobot(std::string target);
        static AForm *makePresid(std::string target);
};

#endif