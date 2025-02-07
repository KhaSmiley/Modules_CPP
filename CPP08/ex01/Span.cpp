/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 05:38:08 by kboulkri          #+#    #+#             */
/*   Updated: 2025/02/07 06:23:42 by kboulkri         ###   ########.fr       */
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
    if (_v.size() < _n)
        _v.push_back(n);
    else
        throw std::exception();
}

void Span::iteratorNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    srand(time(NULL));
    std::vector<int>::iterator it;

    for_each(s.begin(), s.end, )
    {
        addNumber(rand() % 3);
    }
}
