/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 13:16:54 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/02/18 15:07:08 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE
#define MATERIASOURCE

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    public:
    
        MateriaSource(void);
        MateriaSource(MateriaSource const &src);
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