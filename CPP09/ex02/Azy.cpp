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

void PmergeMe::check_digits(char **av)
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
    }

void PmergeMe::push_pairs()
{
    std::vector<std::pair<int, int> >::iterator it;
    it = _makepairs.begin();
    for(; it != _makepairs.end(); it++)
    {
        _numbers_smallest.push_back(it->second);
        _numbers_largest.push_back(it->first);
    }
}
    
void PmergeMe::merge_sort(std::vector<std::pair<int, int> > &pairs, int begin, int mid, int end)
{
	std::vector<std::pair<int, int> > temp(end - begin + 1);
	std::merge(pairs.begin() + begin, pairs.begin() + mid + 1,
	           pairs.begin() + mid + 1, pairs.begin() + end + 1, temp.begin(),
	           ComparePairs());
	std::copy(temp.begin(), temp.end(), pairs.begin() + begin);
}

void PmergeMe::split_sort_pairs(std::vector<std::pair<int, int> > &pairs, int begin, int end)
{
    int halfArray = 0;

    if (begin >= end)
        return ;
    halfArray = begin + (end - begin) / 2;
    split_sort_pairs(pairs, begin, halfArray);
    split_sort_pairs(pairs, halfArray + 1, end);
    merge_sort(pairs, begin, halfArray, end);
}