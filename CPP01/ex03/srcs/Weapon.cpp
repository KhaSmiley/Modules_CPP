/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:37:01 by kboulkri          #+#    #+#             */
/*   Updated: 2024/10/29 19:52:02 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Weapon.hpp"

void Weapon::setType(std::string type)
{
    this->type = type;
}
Weapon::Weapon(std::string type)
{
    this->type = type;
}

Weapon::~Weapon()
{
}

const std::string &Weapon::getType()
{
    return (this->type);
}