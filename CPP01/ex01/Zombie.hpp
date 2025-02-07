/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 21:02:18 by kboulkri          #+#    #+#             */
/*   Updated: 2024/09/18 12:15:14 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */

class Zombie
{
  public:
	Zombie();
	~Zombie();
	std::string get_name();
    std::string SetName(std::string);
	void announce();

  private:
	std::string name;
};

Zombie *zombieHorde(int, std::string);

#endif