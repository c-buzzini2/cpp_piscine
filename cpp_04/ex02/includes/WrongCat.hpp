/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:15:05 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/02/12 08:24:19 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat: virtual public WrongAnimal
{
        public:
        
        WrongCat(void);
        WrongCat(WrongCat const &src);
        ~WrongCat(void);

        WrongCat & operator=(WrongCat const &src);
        
        void    makeSound() const;
};

#endif