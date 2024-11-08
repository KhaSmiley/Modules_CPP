/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 02:12:32 by kboulkri          #+#    #+#             */
/*   Updated: 2024/11/08 01:09:29 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain :: Default constructor" << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain :: Copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];
}

Brain::~Brain()
{
    std::cout << "Brain :: Destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &src)
{
    std::cout << "Brain :: Assignation operator called" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = src.ideas[i];
	return (*this);
}

void Brain::setIdeas(std::string name)
{
    for (int i = 0; i < 100; i++)
    {
        this->ideas[i] = name;
    }
}

std::string Brain::getIdeas(int index)
{
    return(this->ideas[index]);
}