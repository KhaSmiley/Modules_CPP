/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 05:38:11 by kboulkri          #+#    #+#             */
/*   Updated: 2025/02/08 11:09:46 by kboulkri         ###   ########.fr       */
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

        unsigned int getSize() const;
        void print_vector();

        void addNumber(int n);
        void iteratorNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);

        int shortestSpan();
        int longestSpan();

        class TooManyNumbers : public std::exception
        {
            public :

                virtual const char *what() const throw()
                {
                    return ("Too many numbers stocked");
                }
        };

        class NotEnoughNumbers : std::exception
        {
            public :

                virtual const char *what() const throw()
                {
                    return ("Not enough numbers stocked");
                }
        };
        
    private :
        
        unsigned int _n;
        std::vector<int> _v;  
};