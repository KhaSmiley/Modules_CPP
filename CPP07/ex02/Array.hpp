/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 22:14:49 by kboulkri          #+#    #+#             */
/*   Updated: 2025/02/06 21:29:15 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include <ctime>
#include <cstdlib>
#include <string>

#define RESET   "\033[0m"
#define RED	 "\033[31m"
#define BLUE	"\033[34m" 
#define YELLOW  "\033[33m"
#define GREEN   "\033[32m"

template <typename T>

class Array
{
    public :

    Array();
    Array(unsigned int nb);
    Array(const Array &src);
    Array & operator=(const Array &rhs);
    T &operator[](unsigned int nb);
    const T &operator[](const unsigned int nb) const;
    ~Array();

    unsigned int size() const;
    T getValue(unsigned int i) const;
    void setValue(unsigned int i, T value);

    class OutofBound : public std::exception
    {
        public :
        
            virtual const char *what() const throw()
            {
                return ("Out of Bounds");
            }
    };
    
    private :  

        T *_array;
        unsigned int _size;
};

template <typename T>

Array<T>::Array() : _array(new T[0]), _size(0)
{
    std::cout << BLUE << "Array constructor by default" << RESET << std::endl;
}

template <typename T>

Array<T>::Array(const Array &src) : _array(new T[src._size]), _size(src._size) 
{
    for(unsigned int i = 0; i < this->_size; i++)
    {
        this->_array[i] = src._array[i];
    }
}

template <typename T>

Array<T>::Array(unsigned int nb) : _array(new T[nb]), _size(nb)
{
    std::cout << BLUE <<"Array constructor unsigned int default" << RESET << std::endl;
}
template <typename T>

Array<T>::~Array()
{
    delete [] this->_array;
}

template <typename T>

Array<T> & Array<T>::operator=(const Array &rhs)
{
    if (*this != &rhs)
    {
        delete[] this->_array;
        this->_size = rhs._size;
        this->_array = new T[this->_size];
        for (unsigned int i = 0; i < this->_size; i++)
        {
            this->_array[i] = rhs._array[i];
        }
    }
    return *this;
}

template <typename T>

T & Array<T>::operator[](unsigned int nb)
{
    if (nb >= this->_size || nb < 0)
        throw OutofBound();
    return (this->_array[nb]);    
}

template <typename T>

const T & Array<T>::operator[](const unsigned int nb) const
{
    if (nb >= this->_size || nb < 0)
        throw OutofBound();
    return (this->_array[nb]);    
}

template <typename T>

T Array<T>::getValue(unsigned int i) const
{
    return (this->_array[i]);
}

template <typename T>

unsigned int Array<T>::size() const
{
    return (this->_size);
}

template <typename T>

void Array<T>::setValue(unsigned int i, T value)
{
    if (i >= _size)
        throw OutofBound();
    this->_array[i] = value;
}