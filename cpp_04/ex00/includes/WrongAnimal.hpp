/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 11:42:51 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/02/12 09:12:34 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
    public:
        
        WrongAnimal(void);
        WrongAnimal(WrongAnimal const &src);
        virtual ~WrongAnimal(void);

        WrongAnimal & operator=(WrongAnimal const &src);

        void    makeSound() const;
        std::string     getType() const;
    
    protected:
      
        std::string type;
};

#endif