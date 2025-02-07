/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:43:08 by kboulkri          #+#    #+#             */
/*   Updated: 2024/10/26 18:54:06 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    public :
        
        Fixed(void);
        Fixed(Fixed const & src);
        ~Fixed(void);
        
        Fixed & operator=(Fixed const & rhs);
        
        int getRawBits(void) const;
        void setRawBits(int const raw);
    private :
    
    int _value;  
    static const int _fractional_bits = 8;
};

#endif