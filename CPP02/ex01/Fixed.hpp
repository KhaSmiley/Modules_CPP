/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:43:05 by kboulkri          #+#    #+#             */
/*   Updated: 2024/10/29 13:57:20 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>


class Fixed
{
    public :

    Fixed(void);
    Fixed(Fixed const & src);
    Fixed(const int value);
    Fixed(const float value);
    ~Fixed(void);
    
    float toFloat(void) const;
    int toInt(void) const;
    int getRawBits(void) const;
    void setRawBits(int const raw);
    Fixed & operator=(Fixed const & rhs);

    
    private :

    int _value;
    static const int _fractional_bits = 8;
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif