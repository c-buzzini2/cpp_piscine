/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 11:21:28 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/03/03 09:58:21 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

# include <stdlib.h>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm(void);
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm& src);
        AForm& operator=(const AForm& src);
        ~RobotomyRequestForm(void);
        
        void        execute(Bureaucrat const & exctr) const;
        std::string getTarget(void) const;
        void        action(void) const;

    private:
        std::string _target;
};

#endif