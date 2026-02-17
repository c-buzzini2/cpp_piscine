/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 13:16:54 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/02/17 11:51:40 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE
#define MATERIASOURCE

# include "IMateriaSource.hpp"

//START HERE!!!! implement functions, then make sure character is allicating everything
//Also go back to ice and cure to check that they give the target's name
//Make sure Chaacter and materiasource check for total of 4
class MateriaSource : public IMateriaSource
{
    public:
    
        MateriaSource(void);
        MateriaSource(MateriaSource const &src);
		MateriaSource(std::string const &name);
        MateriaSource & operator=(MateriaSource const &src);
        virtual ~MateriaSource(void);
        
        virtual void        learnMateria(AMateria*);
        virtual AMateria*   createMateria(std::string const & type);

        AMateria*   _learned[4];
        int         _mat_total;
        void        _init_arr(AMateria **arr);
        void        _free_arr(AMateria **arr);
};

#endif