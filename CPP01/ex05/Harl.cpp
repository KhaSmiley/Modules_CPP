/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:58:52 by kboulkri          #+#    #+#             */
/*   Updated: 2024/10/16 15:14:19 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
    functab[0] = &Harl::debug;
    functab[1] = &Harl::info;
    functab[2] = &Harl::warning;
    functab[3] = &Harl::error;
    _level[0] = "DEBUG";
    _level[1] = "INFO";
    _level[2] = "WARNING";
    _level[3] = "ERROR";
}

Harl::~Harl()
{
}

void Harl::complain(std::string level)
{
    for(int i = 0; i < 4; i++)
    {
        if (this->_level[i] == level)
        {
            (this->*functab[i])();
            break;
        }
    }
}

void Harl::debug ( void )
{
	std::cout << "Use valgrind to see details of leaked memory" << std::endl;
}

void Harl::info ( void )
{
	std::cout << "At this point it's forbidden to still have leaks" << std::endl;
}

void Harl::warning ( void )
{
	std::cout << "You should be ready to get a flag \"Leaks\" at the correction" << std::endl;
}

void Harl::error ( void )
{
	std::cout << "You got a 0, you can retry this project in 2 weeks" << std::endl;
}