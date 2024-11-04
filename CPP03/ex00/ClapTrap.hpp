/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:31:59 by kboulkri          #+#    #+#             */
/*   Updated: 2024/11/03 23:58:48 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class ClapTrap
{
    public :

    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap& src);
    ~ClapTrap();
    ClapTrap & operator=(ClapTrap const & rhs);
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    void setName(std::string name);
    void setHitPoints(int hit_points);
    void setEnergyPoints(int energy_points);
    void setAttackDamage(int attack_damage);

    std::string getName();
    int getHitPoints();
    int getEnergyPoints();
    int getAttackDamage();

    void printinfo();

    private :
    
    std::string _name;
    int _hit_points;
    int _energy_points;
    int _attack_damage;
};