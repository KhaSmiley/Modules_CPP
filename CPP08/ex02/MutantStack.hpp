/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:41:39 by kboulkri          #+#    #+#             */
/*   Updated: 2025/02/08 11:45:42 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>
#include <string>
#include <list>

template <typename T>

class MutantStack : public std::stack<T>
{
    public :

        typedef typename std::stack<T>::container_type::iterator iterator;
        MutantStack();
        MutantStack(const MutantStack &src);
        MutantStack &operator=(const MutantStack &rhs);
        ~MutantStack();

        iterator begin();
        iterator end();
};

template <typename T>

MutantStack<T>::MutantStack(){}

template <typename T>

MutantStack<T>::MutantStack(const MutantStack &src) : std::stack<T>(src)
{}

template <typename T>

MutantStack<T>::~MutantStack() {}

template <typename T>

MutantStack<T>& MutantStack<T>::operator=(const MutantStack &rhs)
{
    this->c = rhs.c;
    return *this;
}

template <typename T>

typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return(this->c.begin());
}

template <typename T>

typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return(this->c.end());
}

#endif