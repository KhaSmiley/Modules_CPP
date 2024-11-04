/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:32:02 by kboulkri          #+#    #+#             */
/*   Updated: 2024/11/04 02:48:19 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() 
{    
    ClapTrap Kimura("Kimura");
    ClapTrap Aoki("Aoki");
    ScavTrap Takamura("Takamura");
    std::cout << std::endl;

    Kimura.setEnergyPoints(5);
    Kimura.setAttackDamage(0);
    Kimura.setHitPoints(10);
    Kimura.printinfo();
    std::cout << std::endl;

    Aoki.setEnergyPoints(5);
    Aoki.setAttackDamage(0);
    Aoki.setHitPoints(10);
    Aoki.printinfo();
    std::cout << std::endl;

    Takamura.setEnergyPoints(100);
    Takamura.setAttackDamage(100);
    Takamura.setHitPoints(100);
    Takamura.printinfo();
    std::cout << std::endl;
    
    std::cout << std::endl;
    Kimura.attack("Takamura");
    Takamura.takeDamage(Kimura.getAttackDamage());
    Aoki.attack("Takamura");
    Takamura.takeDamage(Aoki.getAttackDamage());
    Takamura.guardGate();
    Takamura.attack("Kimura");
    Kimura.takeDamage(Takamura.getAttackDamage());
    Takamura.attack("Aoki");
    Aoki.takeDamage(Takamura.getAttackDamage());
    
    std::cout << std::endl;
    Kimura.printinfo();
    std::cout << std::endl;
    Aoki.printinfo();
    std::cout << std::endl;
    Takamura.printinfo();
    std::cout << std::endl;
    
    return 0;
}
