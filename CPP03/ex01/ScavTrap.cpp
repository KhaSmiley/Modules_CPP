/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 01:35:53 by kboulkri          #+#    #+#             */
/*   Updated: 2024/11/04 02:43:34 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "ScavTrap Default constructor called" << std::endl;
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_attack_damage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "ScavTrap constructor called" << std::endl;
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_attack_damage = 20;
}
ScavTrap::ScavTrap(ScavTrap const & src)
{
    std::cout << "ScavTrap Copy constructor called" << std::endl;
    this->_name = src._name;
    this->_attack_damage = src._attack_damage;
    this->_hit_points = src._hit_points;
    this->_energy_points = src._energy_points;
    return ;
}
ScavTrap& ScavTrap::operator=(ScavTrap const & src)
{
    std::cout << "ScavTrap Copy assignment operator called" << std::endl;
    this->_name = src._name;
    this->_attack_damage = src._attack_damage;
    this->_hit_points = src._hit_points;
    this->_energy_points = src._energy_points;
    return *this;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap Destructor has been called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (this->_energy_points > 0)
    {
        std::cout << "ScavTrap " << this->_name << " attack " << target << " causing " << this->_attack_damage << " points of damage ! 🥊" << std::endl;
        this->_energy_points--;
    }
    else
        std::cout << "ScavTrap " << this->_name << " can't attack" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->_name << " have enterred in Gate keeper mode !" << std::endl;
}