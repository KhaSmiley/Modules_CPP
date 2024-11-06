/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 02:12:32 by kboulkri          #+#    #+#             */
/*   Updated: 2024/11/06 03:28:14 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain default constructor" << std::endl;
}

Brain::Brain(const Brain &src)
{
    *this = src;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(Brain const &rhs)
{
    // this->setIdeas = rhs.getIdeas
}