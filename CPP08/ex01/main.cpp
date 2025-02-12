/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 05:38:11 by kboulkri          #+#    #+#             */
/*   Updated: 2025/02/10 22:51:24 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{

    std::cout << " -------- First test --------\n";
    
    try
    {
        Span test(6);

        test.addNumber(6);
        test.addNumber(3);
        test.addNumber(17);
        test.addNumber(9);
        test.addNumber(11);
        // test.addNumber(12);
        
        std::cout << test.shortestSpan() << std::endl;
        std::cout << test.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << " -------- Second test --------\n";
    try
    {
        std::vector<int> myvec;  // Ensure this is big enough
        Span plouf(10000);  // Make sure `plouf` has enough space
        for(int i = 0; i < 10000; i++)
        {
            myvec.push_back(i);
        }
        plouf.iteratorNumber(myvec.begin(), myvec.end());
        std::cout << "Shortest = " << plouf.shortestSpan() << std::endl;
        std::cout << "Longest = " << plouf.longestSpan() << std::endl;
        // plouf.addNumber(9);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
}