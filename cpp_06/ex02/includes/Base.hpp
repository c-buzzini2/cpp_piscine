/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 11:08:19 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/03/31 14:00:22 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <cstdlib>

class Base
{
    public:
        virtual ~Base(void);
		static Base* generate(void);
        static void identify(Base* p);
        static void identify(Base& p);
};

class A : public Base {};
class B : public Base {};
class C : public Base {};


#endif