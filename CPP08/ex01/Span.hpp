/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 05:38:06 by kboulkri          #+#    #+#             */
/*   Updated: 2025/02/07 06:23:16 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
    public :
    
        Span();
        Span(unsigned int n);
        Span(Span const & src);
        Span & operator=(Span const & src);
        ~Span();

        void addNumber(int n);
        void Span::iteratorNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        
    private :
        
        unsigned int _n;
        std::vector<int> _v;  
};