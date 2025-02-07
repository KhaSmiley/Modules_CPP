/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:43:13 by kboulkri          #+#    #+#             */
/*   Updated: 2024/10/29 19:44:31 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


Zombie::Zombie(std::string name)
{
    std::cout << "Zombie " << name << " is born" << std::endl;
    this->name = name;
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << this->name << " is dead" << std::endl;
}

std::string Zombie::get_name()
{
    return (this->name);
}

void Zombie::announce()
{
    std::cout << get_name() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
