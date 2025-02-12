/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 05:38:11 by kboulkri          #+#    #+#             */
/*   Updated: 2025/02/10 22:51:34 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _n(0) {}

Span::Span(unsigned int n) : _n(n) {}

Span::Span(Span const & src) : _n(src._n), _v(src._v) {}

Span & Span::operator=(Span const & src)
{
    if (this != &src)
    {
        _n = src._n;
        _v = src._v;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int n)
{
    if (_v.size() >= _n)
        throw TooManyNumbers();
    _v.push_back(n);
}

void Span::iteratorNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{   
    if (_v.size() + std::distance(begin, end) > _n)
        throw TooManyNumbers();
    srand(time(NULL));
    for(std::vector<int>::iterator it = begin; it != end; ++it)
    {
        addNumber(rand());
    }
}

int Span::shortestSpan()
{
    if (_v.size() < 2)
        throw NotEnoughNumbers();
    int min;
    std::sort(_v.begin(), _v.end());
    std::vector<int>::iterator it = _v.begin();
    std::vector<int>::iterator it2 = it;
    it2++;
    min = (*it2) - (*it);
    while(it2 != _v.end())
    {
        if ((*it2) - *it < min)
            min = (*it2) - *it;
        it2++;
        it++;   
    }
    return (min);
}

int Span::longestSpan()
{
    if (_v.size() < 2)
        throw NotEnoughNumbers();
    int max;
    std::sort(_v.begin(), _v.end());
    std::vector<int>::iterator it = _v.begin();
    max = _v.back() - (*it);
    return (max);
}

unsigned int Span::getSize() const
{
    return (this->_n);
}

void Span::print_vector()
{
    for(std::vector<int>::iterator loup = _v.begin(); loup != _v.end(); loup++)
    {
        std::cout << *loup << std::endl;
    }
}
