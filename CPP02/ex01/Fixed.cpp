/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:43:02 by kboulkri          #+#    #+#             */
/*   Updated: 2024/10/29 14:29:44 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
    return ;
}
Fixed::Fixed(int value)
{
    std::cout << "Int constructor called" << std::endl;
    this->_value = value << this->_fractional_bits;
    return ;
}

Fixed::Fixed(float value)
{
    std::cout << "Float constructor called" << std::endl;
    this->_value = roundf(value * (1 << this->_fractional_bits));
    return ;
}
Fixed::Fixed(Fixed const & src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
    return ;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
    return ;
}
Fixed & Fixed::operator=(Fixed const & rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->_value = rhs.getRawBits();
    return *this;
}

void Fixed::setRawBits(int const raw)
{
    // std::cout << "setRawBits member function called" << std::endl;
    this->_value = raw;
}

int Fixed::getRawBits(void) const
{
    // std::cout << "getRawBits member function called" << std::endl;
    return this->_value;
}

int Fixed::toInt(void) const
{
    return this->_value >> this->_fractional_bits;
}

float Fixed::toFloat(void) const
{
    return (float)this->_value / (1 << this->_fractional_bits);
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
    o << rhs.toFloat();
    return o;
}