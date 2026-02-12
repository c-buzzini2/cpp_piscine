/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animals.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 11:42:51 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/02/12 14:09:48 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMALS_HPP
#define ANIMALS_HPP

# include <iostream>

class Animal
{
    public:
        
        Animal(void);
        Animal(Animal const &src);
        virtual ~Animal(void);

        Animal & operator=(Animal const &src);

        virtual void    makeSound() const = 0;
        std::string     getType() const;
    
    protected:
      
        std::string type;
};

#endif