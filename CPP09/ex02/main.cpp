/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 05:35:13 by kboulkri          #+#    #+#             */
/*   Updated: 2025/02/21 03:32:19 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    try
    {
        if (ac < 2)
            throw std::invalid_argument("Error: No arguments");
        PmergeMe Vector;
        clock_t v_time = clock();
        Vector.parse(av);
        v_time = clock() - v_time;
        std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector : " << (float)v_time * 1000 / CLOCKS_PER_SEC << "ms" << std::endl;

        PmergeMeDeque Deque;
        clock_t d_time = clock();
        Deque.parse(av);
        d_time = clock() - d_time;
        std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque : " << (float)d_time * 1000 / CLOCKS_PER_SEC << "ms" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}