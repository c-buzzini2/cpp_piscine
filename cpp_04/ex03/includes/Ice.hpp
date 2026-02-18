/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 21:40:37 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/02/18 08:22:43 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria
{
    public:
        
        Ice(void);
        Ice(Ice const &src);
        virtual ~Ice(void);
        Ice & operator=(Ice const &src);

        virtual void        use(ICharacter& target);
        virtual AMateria*   clone() const;
};

#endif