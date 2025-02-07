/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 21:03:10 by kboulkri          #+#    #+#             */
/*   Updated: 2024/09/18 12:14:26 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    std::cout << std::endl << RED << "███████████████████████████" << RESET << std::endl << std::endl;
    std::cout << RED << "DANGER ZOMBIES ARE COMING" << RESET << std::endl;
    std::cout << std::endl << RED << "███████████████████████████" << RESET << std::endl << std::endl;
    Zombie *zombie;
    zombie = zombieHorde(5, "Zombie");
    std::cout <<  RED << "ZOMBIES HAS APPEARED" << RESET << std::endl;
    for (int i = 0; i < 5; i++)
        zombie[i].announce();
    delete [] zombie;
    std::cout << RED << "ZOMBIES ARE DEAD" << RESET << std::endl;
}