/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 11:08:19 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/03/31 11:18:24 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

class Data
{
    public:
        Data(void);
		Data(int n);
        Data(const Data& src);
        Data& operator=(const Data& src);
        ~Data(void);
		
		int		get_nb(void) const;
		void	set_nb(int n);

    private:
        int nb;
};

#endif