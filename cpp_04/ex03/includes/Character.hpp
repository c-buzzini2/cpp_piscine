/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 11:42:51 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/02/18 14:36:08 by cbuzzini         ###   ########.fr       */
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
        int         _floor_total;
        AMateria**   _floor_mat;
        void        _init_arr(AMateria **arr);
        void        _free_arr(AMateria **arr, int size);
        void        _copy_arr(AMateria **dest, AMateria **src, int size);
        void        _send_to_floor(AMateria *m);
    
    public:
      
        Character(void);
        Character(Character const &src);
		Character(std::string const &name);
        Character & operator=(Character const &src);
        virtual ~Character(void);
		
        virtual std::string const & getName() const;
        virtual void equip(AMateria* m);
        virtual void unequip(int idx);
        virtual void use(int idx, ICharacter& target);
};

#endif