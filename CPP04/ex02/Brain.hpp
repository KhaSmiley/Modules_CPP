/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 02:12:30 by kboulkri          #+#    #+#             */
/*   Updated: 2024/11/07 23:26:58 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
    public :

        Brain();
        Brain(const Brain &rhs);
        ~Brain();
        
        Brain &operator=(const Brain &src);

        void setIdeas(std::string name);
        std::string getIdeas(int index);
        
    private :

        std::string ideas[100];
};

#endif