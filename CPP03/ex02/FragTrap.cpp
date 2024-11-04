/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 02:56:57 by kboulkri          #+#    #+#             */
/*   Updated: 2024/11/04 03:16:25 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "FragTrap Default constructor called" << std::endl;
}
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "FragTrap constructor called" << std::endl;
    this->_hit_points = 100;
    this->_energy_points = 100;
    this->_attack_damage = 30;
    return ;
}

FragTrap::FragTrap(const FragTrap& src)
{
    std::cout << "Copy constructor called" << std::endl;
    this->_name = src._name;
    this->_attack_damage = src._attack_damage;
    this->_hit_points = src._hit_points;
    this->_energy_points = src._energy_points;
    return ;
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap destructor has been called" << std::endl;
}

FragTrap & FragTrap::operator=(FragTrap const & rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->_name = rhs._name;
    this->_attack_damage = rhs._attack_damage;
    this->_hit_points = rhs._hit_points;
    this->_energy_points = rhs._energy_points;
    return *this;
}

void FragTrap::attack(const std::string& target)
{
    if (this->_energy_points > 0)
    {
        std::cout << "FragTrap " << this->_name << " attack " << target << " causing " << this->_attack_damage << " points of damage ! 🥊" << std::endl;
        this->_energy_points--;
    }
    else
        std::cout << "FragTrap " << this->_name << " can't attack" << std::endl;
}


void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->_name << " is asking for a high five 🖐" << std::endl;
}