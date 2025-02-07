/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:08:23 by kboulkri          #+#    #+#             */
/*   Updated: 2024/09/24 17:17:35 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <iostream>

class HumanB
{
    public:
    
    HumanB(std::string name);
    ~HumanB();
    void attack(void);
    void setWeapon(Weapon &weapon);
    
    private:
    
    std::string name;
    Weapon* weapon;
};

#endif