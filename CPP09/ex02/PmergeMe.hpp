/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 05:35:17 by kboulkri          #+#    #+#             */
/*   Updated: 2025/02/21 03:25:47 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <utility>
#include <algorithm>

class PmergeMe
{
    public:
    
        PmergeMe();
        PmergeMe(const PmergeMe &src);
        PmergeMe &operator=(const PmergeMe &src);
        ~PmergeMe();
        
        void parse(char **av);
        void check_duplicates(char **av);
        void add_av(char **av);
        void make_pairs();
        void sort_pairs();
        void push_pairs();
        void split_sort_pairs();

    private:

        std::vector<int> _av;
        std::vector<std::pair<int, int> > _makepairs;
        int _straggler;
        std::vector<int> _numbers_smallest;
        std::vector<int> _numbers_largest;
};

#endif