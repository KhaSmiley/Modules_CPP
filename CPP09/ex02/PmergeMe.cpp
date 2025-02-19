/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 05:35:13 by kboulkri          #+#    #+#             */
/*   Updated: 2025/02/19 05:22:54 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &src)
{
    *this = src;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
    if (this != &src)
    {
    }
    return *this;
}

PmergeMe::~PmergeMe()
{
}


void PmergeMe::check_duplicates(char **av)
{
    int i = 1;
    
    while (av[i])
    {
        if (atoi(av[i]) < 0)
        {
            throw std::invalid_argument("Error: Only positive numbers are allowed");
        }
        int j = i + 1;
        while (av[j])
        {
            
            if (atoi(av[i]) == atoi(av[j]))
            {
                throw std::invalid_argument("Error: Duplicate argument");
            }
            j++;
        }
        i++;
    }
}

void check_digits(char **av)
{
    int i = 1;
    
    while (av[i])
    {
        int j = 0;
        int sign = 0;
        while (av[i][j])
        {
            while (av[i][j] && (av[i][j] == '-' || av[i][j] == '+'))
            {
                sign++;
                if (sign > 1)
                {
                    throw std::invalid_argument("Error: Invalid argument");
                }
                j++;
            }
            while (isdigit(av[i][j]))
                j++;
            if (av[i][j] && !isdigit(av[i][j]))
            {
                throw std::invalid_argument("Error: Invalid argument");
            }
        }
        i++;
    }
}

void PmergeMe::parse(char **av)
{
    check_digits(av);
    check_duplicates(av);
}