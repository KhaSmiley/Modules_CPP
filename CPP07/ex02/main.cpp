/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:04:56 by kboulkri          #+#    #+#             */
/*   Updated: 2025/02/06 21:26:26 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
    std::cout << RED << "Array of int with a size of 5" << RESET << std::endl;
    Array<int> a(5);
    srand(time(NULL));
    for(unsigned int i = 0; i < 5; i++)
    {
        a.setValue(i, rand() % 3);   
        std::cout << YELLOW << "Random value from Int array[" << i << "] -> " << a.getValue(i) << RESET << std::endl;
    }

    std::cout << std::endl << RED << "Array of float with a size of 3" << std::endl;
    Array<float> b(3);
    b.setValue(0, 1.0);
    b.setValue(1, 42.0); 
    b.setValue(2, 4.2);
    for(unsigned int i = 0; i < 3; i++)
    {
        std::cout << YELLOW << "Value from float array[" << i << "] -> " << b.getValue(i) << RESET << std::endl;
    }
    
    std::cout << std::endl << RED << "Array of string with a size of 3 + OutofBound" << std::endl;
    Array<std::string> c(3);
    try
    {
        c.setValue(0, "Dans");
        c.setValue(1, "la");
        c.setValue(2, "Zone");
        for (unsigned int i = 0; i < 3; i++)
        {
            std::cout << YELLOW << "Value from string array[" << i << "] -> " << c.getValue(i) << RESET << std::endl;
        }
        std::cout << RED << "Now trying to create a string that is out of bound" << RESET << std::endl;
        c.setValue(3, "OUT OF BOUND");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}