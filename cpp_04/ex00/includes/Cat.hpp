/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:15:05 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/02/12 08:24:19 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

# include "Animals.hpp"

class Cat: virtual public Animal
{
        public:
        
        Cat(void);
        Cat(Cat const &src);
        ~Cat(void);

        Cat & operator=(Cat const &src);
        
        void    makeSound() const;
};

#endif