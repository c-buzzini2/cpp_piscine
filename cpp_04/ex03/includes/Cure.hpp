/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 21:40:37 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/02/16 14:21:21 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria
{
    public:
        
        Cure(void);
        Cure(Cure const &src);
        virtual ~Cure(void);
        Cure & operator=(Cure const &src);

        virtual void        use(ICharacter& target);
        virtual AMateria*   clone() const;
};

#endif