/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 11:42:51 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/02/18 08:34:23 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class AMateria
{
    public:
        
        AMateria(void);
        AMateria(AMateria const &src);
        AMateria(std::string const & type);
        virtual ~AMateria(void);
        AMateria & operator=(AMateria const &src);

        virtual void        use(ICharacter& target);
        virtual AMateria*   clone() const = 0;
        std::string const & getType() const;
    
    protected:
      
        std::string type;
};

#endif