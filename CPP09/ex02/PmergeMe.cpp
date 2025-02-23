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

// ------------------------------- Constructor / Destructor Vector -------------------------------

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

// ------------------------------- Constructor / Destructor Deque -------------------------------

PmergeMeDeque::PmergeMeDeque() {}

PmergeMeDeque::PmergeMeDeque(const PmergeMeDeque &src)
{
    *this = src;
}

PmergeMeDeque &PmergeMeDeque::operator=(const PmergeMeDeque &src)
{
    if (this != &src)
    {
        _av = src._av;
    }
    return *this;
}

PmergeMeDeque::~PmergeMeDeque() {}

// ------------------------------- Parsing -------------------------------

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
                    throw std::invalid_argument("Error1: Invalid argument");
                }
                j++;
            }
            while (isdigit(av[i][j]))
                j++;
            if (av[i][j] && !isdigit(av[i][j]))
            {
                throw std::invalid_argument("Error2: Invalid argument");
            }
        }
        i++;
    }
}

void PmergeMeDeque::check_duplicates(char **av)
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

void PmergeMeDeque::check_digits(char **av)
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

// ------------------------------- Vector -------------------------------

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

void PmergeMe::insert_into_sorted(void)
{
    // Insère le plus petit élément en premier
    _numbers_largest.insert(_numbers_largest.begin(), _numbers_smallest[0]);

    // Insère les éléments restants en utilisant les indices Jacobsthal
    for (size_t i = 0; i < _indexes.size(); ++i) // Utilisation d'une boucle classique
    {
        size_t index = _indexes[i];
        if (index < 1 || index > _numbers_smallest.size()) {
            std::cerr << "Index out of bounds: " << index << std::endl;
            continue; // Ou gérez l'erreur comme vous le souhaitez
        }
        int to_push = _numbers_smallest.at(index - 1); // Récupère l'élément à insérer

        // Trouve la position d'insertion
        size_t pos = 0;
        while (pos < _numbers_largest.size() && _numbers_largest[pos] < to_push)
        {
            pos++; // Trouve la première position où to_push doit être inséré
        }
        
        _numbers_largest.insert(_numbers_largest.begin() + pos, to_push); // Insère à la position trouvée
    }


    // Si la liste d'origine a un nombre impair d'éléments, insère le straggler
    if (_av.size() % 2 != 0)
    {
        // Récupère le dernier élément
        size_t pos = 0;
        while (pos < _numbers_largest.size() && _numbers_largest[pos] < _straggler)
        {
            pos++; // Trouve la première position où straggler doit être inséré
        }
        _numbers_largest.insert(_numbers_largest.begin() + pos, _straggler); // Insère à la position trouvée
    }
}

void PmergeMe::fill_insertion_indices()
{
    if (_numbers_smallest.empty())
        return;

    size_t last_pos = 1;

    // Ajoute les indices selon la séquence de Jacobsthal
    for (size_t i = 0; i < _jacobsthal.size(); i++)
    {
        _indexes.push_back(_jacobsthal[i]);

        // Ajoute les indices intermédiaires entre last_pos et la valeur actuelle de Jacobsthal
        for (size_t j = _jacobsthal[i] - 1; j > last_pos; j--)
        {
            _indexes.push_back(j);
        }

        last_pos = _jacobsthal[i]; // Mise à jour de la dernière position atteinte
    }
    // Ajoute les indices restants jusqu'à la taille de _sorted
    for (size_t i = last_pos + 1; i <= _numbers_largest.size(); i++)
    {
        _indexes.push_back(i);
    }
}


int	PmergeMe::jacobsthal_sequence(int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return (jacobsthal_sequence(n - 1) + 2 * jacobsthal_sequence(n - 2));
}

// create vector of jaobsthal numbers
void	PmergeMe::stock_jacobsthal_sequence(void)
{
	size_t size;
	size_t jacobindex;
	int index;

	size = _numbers_smallest.size();
	index = 3;
	while ((jacobindex = jacobsthal_sequence(index)) <= size)
	{
		_jacobsthal.push_back(jacobindex);
		index++;
	}
}

void PmergeMe::parse(char **av)
{
    check_digits(av);
    check_duplicates(av);
    add_av(av);
    make_pairs();
    sort_pairs();
    split_sort_pairs(_makepairs, 0, _makepairs.size() - 1);
    push_pairs();
    stock_jacobsthal_sequence();
    fill_insertion_indices();
    insert_into_sorted(); 
}

// ------------------------------- Deque -------------------------------

void PmergeMeDeque::insert_into_sorted(void)
{
    _numbers_largest.push_front(_numbers_smallest[0]);

    for (size_t i = 0; i < _indexes.size(); ++i)
    {
        size_t index = _indexes[i];
        if (index < 1 || index > _numbers_smallest.size()) {
            std::cerr << "Index out of bounds: " << index << std::endl;
            continue;
        }
        int to_push = _numbers_smallest.at(index - 1);
        
        size_t pos = 0;
        while (pos < _numbers_largest.size() && _numbers_largest[pos] < to_push)
        {
            pos++;
        }
        
        _numbers_largest.insert(_numbers_largest.begin() + pos, to_push);
    }

    if (_av.size() % 2 != 0)
    {
        size_t pos = 0;
        while (pos < _numbers_largest.size() && _numbers_largest[pos] < _straggler)
        {
            pos++;
        }
        _numbers_largest.insert(_numbers_largest.begin() + pos, _straggler);
    }
}

void PmergeMeDeque::fill_insertion_indices()
{
    if (_numbers_smallest.empty())
        return;

    size_t last_pos = 1;

    for (size_t i = 0; i < _jacobsthal.size(); i++)
    {
        _indexes.push_back(_jacobsthal[i]);

        for (size_t j = _jacobsthal[i] - 1; j > last_pos; j--)
        {
            _indexes.push_back(j);
        }

        last_pos = _jacobsthal[i];
    }

    for (size_t i = last_pos + 1; i <= _numbers_largest.size(); i++)
    {
        _indexes.push_back(i);
    }
}

int PmergeMeDeque::jacobsthal_sequence(int n)
{
    if (n == 0)
        return (0);
    if (n == 1)
        return (1);
    return (jacobsthal_sequence(n - 1) + 2 * jacobsthal_sequence(n - 2));
}

void PmergeMeDeque::stock_jacobsthal_sequence(void)
{
    size_t size;
    size_t jacobindex;
    int index;

    size = _numbers_smallest.size();
    index = 3;
    while ((jacobindex = jacobsthal_sequence(index)) <= size)
    {
        _jacobsthal.push_back(jacobindex);
        index++;
    }
}

void PmergeMeDeque::merge_sort(std::deque<std::pair<int, int> > &pairs, int begin, int mid, int end)
{
    std::deque<std::pair<int, int> > temp(end - begin + 1);
    std::merge(pairs.begin() + begin, pairs.begin() + mid + 1,
               pairs.begin() + mid + 1, pairs.begin() + end + 1, temp.begin(),
               ComparePairs());
    std::copy(temp.begin(), temp.end(), pairs.begin() + begin);
}

void PmergeMeDeque::split_sort_pairs(std::deque<std::pair<int, int> > &pairs, int begin, int end)
{
    int halfArray = 0;
    if (begin >= end)
        return;
    halfArray = begin + (end - begin) / 2;
    split_sort_pairs(pairs, begin, halfArray);
    split_sort_pairs(pairs, halfArray + 1, end);
    merge_sort(pairs, begin, halfArray, end);
}

void PmergeMeDeque::add_av(char **av)
{
    for (int i = 1; av[i]; i++)
        _av.push_back(atoi(av[i]));
}

void PmergeMeDeque::push_pairs()
{
    std::deque<std::pair<int, int> >::iterator it;
    it = _makepairs.begin();
    for(; it != _makepairs.end(); it++)
    {
        _numbers_smallest.push_back(it->second);
        _numbers_largest.push_back(it->first);
    }
}

void PmergeMeDeque::sort_pairs()
{
    std::deque<std::pair<int, int> >::iterator it;
    it = _makepairs.begin();
    for(; it != _makepairs.end(); it++)
    {
        if (it->first < it->second)
        {
            std::swap(it->first, it->second);
        }
    }
}

void PmergeMeDeque::make_pairs()
{
    std::deque<int>::iterator it;
    std::deque<int>::iterator it2;
    it = _av.begin();
    while(it <= _av.end())
    {
        it2 = it + 1;
        if (it2 == _av.end())
        {
            _straggler = *it;
            break;
        }
        if (it2 <= _av.end())
        {
            _makepairs.push_back(std::make_pair(*it, *it2));
        }
        it += 2;
    }
}

void PmergeMeDeque::parse(char **av)
{
    // check_digits(av);
    // check_duplicates(av);
    add_av(av);
    make_pairs();
    sort_pairs();
    split_sort_pairs(_makepairs, 0, _makepairs.size() - 1);
    push_pairs();
    stock_jacobsthal_sequence();
    fill_insertion_indices();
    insert_into_sorted(); 
}