/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:58:45 by kboulkri          #+#    #+#             */
/*   Updated: 2024/10/31 00:46:25 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl
{
    public :
    
    Harl();
    ~Harl();
    void    complain(std::string level);
    typedef void (Harl::*_ptr)(void);
    private :
    
    _ptr   functab[4];
    std::string _level[4];
    void debug();
    void info();
    void warning();    
    void error();
};

#endif