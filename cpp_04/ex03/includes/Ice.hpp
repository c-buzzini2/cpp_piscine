/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 21:40:37 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/02/13 21:48:22 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

# include <iostream>
# include "AMateria.hpp"

//START HERE!!! IMPLEMENT FUNCTIONS IN ice.cpp, THEN USE IT FOR cURE.
//rEMEMBER FOR THE CONSTRUCTORS, THAT THE BASE CLASS SHOULD BE CREATED

class Ice : public Ice
{
    public:
        
        Ice(void);
        Ice(Ice const &src);
        Ice(std::string const & type);
        virtual ~Ice(void);
        Ice & operator=(Ice const &src);

        //virtual void        use(ICharacter& target); do I need to redeclare here????
    
    protected:
      
        std::string type;
};

#endif