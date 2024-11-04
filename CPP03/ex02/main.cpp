/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:32:02 by kboulkri          #+#    #+#             */
/*   Updated: 2024/11/04 03:15:26 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main() 
{    
    ClapTrap Kimura("Kimura");
    ClapTrap Aoki("Aoki");
    ScavTrap Takamura("Takamura");
    FragTrap Ippo("Ippo");
    std::cout << std::endl;

    Kimura.attack("Takamura");
    Takamura.takeDamage(Kimura.getAttackDamage());
    Aoki.attack("Takamura");
    Takamura.takeDamage(Aoki.getAttackDamage());
    Takamura.guardGate();
    Ippo.highFivesGuys();
    std::cout << std::endl;
    return 0;
}
