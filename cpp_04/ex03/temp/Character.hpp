/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 11:42:51 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/02/16 12:54:38 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Character_HPP
#define Character_HPP

# include "ICharacter.hpp"

class Character : public ICharacter
{
    private:
        
		std::string _name;
        AMateria*   _inventory[4];
        int         _mat_total;
        void        _init_arr(AMateria **arr);
        void        _free_arr(AMateria **arr);
    
    public:
      
        Character(void);
        Character(Character const &src);
		Character(std::string const &name);
        Character & operator=(Character const &src);
        virtual ~Character(void);
		
        virtual std::string const & getName() const;
        virtual void equip(AMateria* m);
        virtual void unequip(int idx);
        virtual void use(int idx, Character& target);
};

#endif