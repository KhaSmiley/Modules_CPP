/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:32:02 by kboulkri          #+#    #+#             */
/*   Updated: 2024/11/04 01:33:24 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() 
{    
    ClapTrap Ippo("Ippo");
    ClapTrap Sendo("Sendo");

    std::cout << "████████████████████████████████████" << std::endl << std::endl;

    Ippo.setEnergyPoints(5);
    Ippo.setAttackDamage(5);
    Ippo.setHitPoints(10);
    Ippo.printinfo();
    std::cout << std::endl;

    Sendo.setEnergyPoints(5);
    Sendo.setAttackDamage(6);
    Sendo.setHitPoints(15);
    Sendo.printinfo();

    std::cout << std::endl << "█████████████ROUND 1████████████████" << std::endl << std::endl;
    
    Ippo.attack("Sendo");
    Sendo.takeDamage(Ippo.getAttackDamage());
    Sendo.attack("Ippo");
    Ippo.takeDamage(Sendo.getAttackDamage());

    Ippo.beRepaired(5);
    Sendo.beRepaired(5);
    
    std::cout << std::endl << "█████████████ROUND 2████████████████" << std::endl << std::endl;

    Ippo.attack("Sendo");
    Ippo.attack("Sendo");
    Sendo.takeDamage(Ippo.getAttackDamage() * 2);
    Sendo.attack("Ippo");
    Ippo.takeDamage(Sendo.getAttackDamage());
    Ippo.attack("Sendo");
    Sendo.takeDamage(Ippo.getAttackDamage());
    
    std::cout << std::endl;
        
    std::cout << "Sendo is DOOOOOOOOOOOWWWWNNNNNNNNNNNN" << std::endl;
    std::cout << "1 - 2 - 3 - 4" << std::endl;
    std::cout << "AHHHHHHHHHH SENDO IS TRYING TO GET ON HIS FEET" << std::endl;
    Sendo.beRepaired(5);
    std::cout << "OHHHHH IT SEEMS THAT HE CAN'T" << std::endl;
    std::cout << "5 - 6 - 7 - 8 - 9 - 10" << std::endl;
    std::cout << "IPPO IS THE NEW CHAMPION 🏆" << std::endl;

    std::cout << std::endl << "████████████████████████████████████" << std::endl << std::endl;
    std::cout << "Info final after the fight :" << std::endl << std::endl;;
    Ippo.printinfo();
    std::cout << std::endl;
    Sendo.printinfo();
    std::cout << std::endl << "████████████████████████████████████" << std::endl << std::endl;
    
    return 0;
}
