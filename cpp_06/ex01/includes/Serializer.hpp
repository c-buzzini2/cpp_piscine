/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 11:01:32 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/03/31 11:49:54 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

# include <stdint.h>
# include "Data.hpp"

class Serializer
{
    private:
        Serializer(void);
        Serializer(const Serializer& src);
        Serializer& operator=(const Serializer& src);
        ~Serializer(void);

    public:
		static uintptr_t serialize(Data *ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif