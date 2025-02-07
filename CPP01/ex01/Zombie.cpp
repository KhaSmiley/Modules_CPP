/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 21:02:37 by kboulkri          #+#    #+#             */
/*   Updated: 2024/09/18 11:53:13 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
}

std::string Zombie::get_name()
{
    return (this->name);
}

void Zombie::announce()
{
    std::cout << get_name() << " BraiiiiiiinnnzzzZ..." << std::endl;
}
std::string Zombie::SetName(std::string name)
{
    return (this->name = name);
}