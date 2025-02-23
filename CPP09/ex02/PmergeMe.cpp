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
    for(unsigned long int i = 0; i < _numbers_largest.size(); ++i)
    {
        std::cout << _numbers_largest[i] << std::endl;
    }
}