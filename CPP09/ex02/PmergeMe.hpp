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
#include <stdexcept>
#include <limits.h>
#include <deque>



class PmergeMe
{
    public:
    
        PmergeMe();
        PmergeMe(const PmergeMe &src);
        PmergeMe &operator=(const PmergeMe &src);
        ~PmergeMe();
        
        void parse(char **av);
        void check_duplicates(char **av);
        void check_digits(char **av);
        void add_av(char **av);
        void make_pairs();
        void sort_pairs();
        void push_pairs();
        void split_sort_pairs(std::vector<std::pair<int, int> > &pairs, int begin, int end);
        void merge_sort(std::vector<std::pair<int, int> > &pairs, int begin, int mid, int end);
        void stock_jacobsthal_sequence(void);
        void fill_insertion_indices();
        void insert_into_sorted(void);
        int	 jacobsthal_sequence(int n);
        int  binary_search(std::vector<int> sorted, int to_push, int begin, int end);

        struct ComparePairs
        {
            bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) const
            {
                return a.first < b.first;
            }
        };

        private:

        std::vector<int> _av;
        std::vector<std::pair<int, int> > _makepairs;
        int _straggler;
        std::vector<int> _numbers_smallest;
        std::vector<int> _numbers_largest;
        std::vector<int> _jacobsthal;
        std::vector<int> _indexes;
};

class PmergeMeDeque
{
    public:
        PmergeMeDeque();
        PmergeMeDeque(const PmergeMeDeque &src);
        PmergeMeDeque &operator=(const PmergeMeDeque &src);
        ~PmergeMeDeque();
       
        void parse(char **av);
        void check_duplicates(char **av);
        void check_digits(char **av);
        void add_av(char **av);
        void make_pairs();
        void sort_pairs();
        void push_pairs();
        void split_sort_pairs(std::deque<std::pair<int, int> > &pairs, int begin, int end);
        void merge_sort(std::deque<std::pair<int, int> > &pairs, int begin, int mid, int end);
        void stock_jacobsthal_sequence(void);
        void fill_insertion_indices();
        void insert_into_sorted(void);
        int  jacobsthal_sequence(int n);
        int  binary_search(std::deque<int> sorted, int to_push, int begin, int end);

        struct ComparePairs
        {
            bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) const
            {
                return a.first < b.first;
            }
        };

    private:
        std::deque<int> _av;
        std::deque<std::pair<int, int> > _makepairs;
        int _straggler;
        std::deque<int> _numbers_smallest;
        std::deque<int> _numbers_largest;
        std::deque<int> _jacobsthal;
        std::deque<int> _indexes;
};

#endif