/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:15:05 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/02/12 11:40:37 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

# include "Animals.hpp"
# include "Brain.hpp"

class Dog: virtual public Animal
{
        public:
        
        Dog(void);
        Dog(Dog const &src);
        ~Dog(void);
        Dog & operator=(Dog const &src);
        
        void    makeSound() const;

        private:
        
        Brain *brn;
};

#endif