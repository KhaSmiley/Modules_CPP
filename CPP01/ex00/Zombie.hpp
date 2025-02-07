/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:43:10 by kboulkri          #+#    #+#             */
/*   Updated: 2024/10/29 19:38:26 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie 
{
    public:
    Zombie(std::string name);
    ~Zombie();
    void announce();
    std::string get_name();
    Zombie* newZombie(std::string);
    void randomChump(std::string name);

    private:
    std::string name;

};

#endif