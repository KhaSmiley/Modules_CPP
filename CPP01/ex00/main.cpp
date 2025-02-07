/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:38:07 by kboulkri          #+#    #+#             */
/*   Updated: 2024/09/28 20:39:00 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie zomb1("Bob");
    Zombie *zomb2;
    zomb2 = zomb1.newZombie("Zomb2");
    zomb2->announce();
    zomb2->randomChump("Zomb3");

    delete zomb2;
}