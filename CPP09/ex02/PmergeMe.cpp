/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 05:35:13 by kboulkri          #+#    #+#             */
/*   Updated: 2025/02/21 03:32:19 by kboulkri         ###   ########.fr       */
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
        _av = src._av;
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

void PmergeMe::add_av(char **av)
{
    for (int i = 1; av[i]; i++)
        _av.push_back(atoi(av[i]));
}

void PmergeMe::make_pairs()
{
    std::vector<int>::iterator it;
    std::vector<int>::iterator it2;
    it = _av.begin();
    while(it <= _av.end())
    {
        it2 = it + 1;
        if (it2 == _av.end())
        {
            _straggler = *it;
            break;
        }
        if (it2 <=_av.end())
        {
            _makepairs.push_back(std::make_pair(*it, *it2));
        }
        it += 2;
    }
}

void PmergeMe::sort_pairs()
{
    std::vector<std::pair<int, int> >::iterator it;
    it = _makepairs.begin();
    for(; it != _makepairs.end(); it++)
    {
        if (it->first < it->second)
        {
            std::swap(it->first, it->second);
        }
    }
    it = _makepairs.begin();
}

void PmergeMe::push_pairs()
{
    std::vector<std::pair<int, int> >::iterator it;
    it = _makepairs.begin();
    for(; it != _makepairs.end(); it++)
    {
        _numbers_smallest.push_back(it->first);
        _numbers_largest.push_back(it->second);
    }
}
    
void PmergeMe::split_sort_pairs()
{
    
}

void PmergeMe::parse(char **av)
{
    check_digits(av);
    check_duplicates(av);
    add_av(av);
    make_pairs();
    sort_pairs();
    push_pairs();
    split_sort_pairs();
}