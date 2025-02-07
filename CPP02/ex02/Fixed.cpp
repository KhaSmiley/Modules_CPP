/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:34:42 by kboulkri          #+#    #+#             */
/*   Updated: 2024/10/30 22:50:02 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

//                              CONSTRUCTOR & DESTRUCTOR                      //
Fixed::Fixed(void) : _value(0)
{
    // std::cout << "Default constructor called" << std::endl;
    return ;
}
Fixed::Fixed(int value)
{
    // std::cout << "Int constructor called" << std::endl;
    this->_value = value << this->_fractional_bits;
    return ;
}

Fixed::Fixed(float value)
{
    // std::cout << "Float constructor called" << std::endl;
    this->_value = roundf(value * (1 << this->_fractional_bits));
    return ;
}
Fixed::Fixed(Fixed const & src)
{
    // std::cout << "Copy constructor called" << std::endl;
    *this = src;
    return ;
}

Fixed::~Fixed(void)
{
    // std::cout << "Destructor called" << std::endl;
    return ;
}

//                              OPERATORS OVERLOADING                          //

Fixed & Fixed::operator=(Fixed const & rhs)
{
    // std::cout << "Copy assignment operator called" << std::endl;
    this->_value = rhs.getRawBits();
    return *this;
}

Fixed &Fixed::operator+(Fixed const & rhs)
{
    this->_value += rhs.getRawBits();
    return *this;
}

Fixed  &Fixed::operator-(Fixed const & rhs)
{
    this->_value -= rhs.getRawBits();
    return *this;
}

Fixed &Fixed::operator*(Fixed const & rhs)
{
    this->_value *= rhs.getRawBits() >> 8;
    return *this;
}

Fixed &Fixed::operator/(Fixed const & rhs)
{
    this->_value /= rhs.getRawBits() << this->_fractional_bits;
    return *this;
}

bool Fixed::operator>(Fixed const & rhs)
{
    return this->_value > rhs.getRawBits();
}

bool Fixed::operator<(Fixed const & rhs)
{
    return this->_value < rhs.getRawBits();
}

bool Fixed::operator>=(Fixed const & rhs)
{
    return this->_value >= rhs.getRawBits();
}

bool Fixed::operator<=(Fixed const & rhs)
{
    return this->_value <= rhs.getRawBits();
}
bool Fixed::operator==(Fixed const & rhs)
{
    return this->_value == rhs.getRawBits();
}

bool Fixed::operator!=(Fixed const & rhs)
{
    return this->_value != rhs.getRawBits();
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    this->_value++;
    return tmp;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    this->_value--;
    return tmp;
}

Fixed Fixed::operator++()
{
    this->_value++;
    return *this;
}

Fixed Fixed::operator--()
{
    this->_value--;
    return *this;
}

//                              GETTERS & SETTERS                              //

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

//                          MAX & MIN FUNCTIONS                              //

Fixed & Fixed::min(Fixed &a, Fixed &b)
{
    return a < b ? a : b;
}

Fixed & Fixed::max(Fixed &a, Fixed &b)
{
    return a > b ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a.getRawBits() < b.getRawBits())
        return (a);
    return (b);
}
    
const Fixed & Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a.getRawBits() > b.getRawBits())
        return (a);
    return (b);
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
    o << rhs.toFloat();
    return o;
}