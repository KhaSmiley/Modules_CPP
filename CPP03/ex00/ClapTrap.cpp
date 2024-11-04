/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:31:57 by kboulkri          #+#    #+#             */
/*   Updated: 2024/11/04 01:21:00 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//                      CONSTRUCTOR                          //

ClapTrap::ClapTrap()
{
    this->_name = "Default";
    this->_attack_damage = 0;
    this->_hit_points = 10;
    this->_energy_points = 10;
}

ClapTrap::ClapTrap(std::string name)
{
    std::cout << "ClapTrap Default constructor called" << std::endl;
    this->_name = name;
    this->_hit_points = 10;
    this->_energy_points = 10;
    this->_attack_damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& src)
{
    *this = src;
    return ;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "Destructor has been called" << std::endl;
}
ClapTrap & ClapTrap::operator=(ClapTrap const & rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->_name = rhs._name;
    this->_attack_damage = rhs._attack_damage;
    this->_hit_points = rhs._hit_points;
    this->_energy_points = rhs._energy_points;
    return *this;
}

void ClapTrap::attack(const std::string& target)
{
    (void)target;
    if (getHitPoints() > 0 && getEnergyPoints() > 0)
    {
        std::cout << "ClapTrap " << getName() << " attacks " << target << " causing " << getAttackDamage() << " points of damage ! 🥊" << std::endl;
        setEnergyPoints(getEnergyPoints() - 1);      
    }
    else
        std::cout << getName() << " can't attack" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
    this->_hit_points -= amount;
    if (this->_hit_points <= 0)
        this->_hit_points = 0;
    std::cout << "ClapTrap " << this->_name << " take " << amount << " points of damage ! 💥" << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_energy_points <= 0 || this->_hit_points <= 0)
        std::cout << "You may not repair yourself ! 😵‍💫" << std::endl;
    else
    {
        this->_energy_points--;
        this->_hit_points += amount;
        std::cout << "ClapTrap " << this->_name << " restored " << amount << " points of damage ! 💪" << std::endl;
    }
}

//                      SETTERS                          //

void ClapTrap::setName(std::string name)
{
    this->_name = name;
}
void ClapTrap::setHitPoints(int hit_points)
{
    this->_hit_points = hit_points;
}

void ClapTrap::setEnergyPoints(int energy_points)
{
    this->_energy_points = energy_points;    
}
void ClapTrap::setAttackDamage(int attack_damage)
{
    this->_attack_damage = attack_damage;
}

//                      GETTERS                          //

std::string ClapTrap::getName()
{
    return this->_name;    
}   
int ClapTrap::getHitPoints()
{
    return this->_hit_points;
}
int ClapTrap::getEnergyPoints()
{
    return this->_energy_points;
}    
int ClapTrap::getAttackDamage()
{
    return this->_attack_damage;
}

void ClapTrap::printinfo()
{
    std::cout << "Name : " << getName() << std::endl;
    std::cout << "Energy : " << getEnergyPoints() << std::endl;
    std::cout << "Attack Damage : " << getAttackDamage() << std::endl;
    std::cout << "Hit Points : " << getHitPoints() << std::endl;

}
