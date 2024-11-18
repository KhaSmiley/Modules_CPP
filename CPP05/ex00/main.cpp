/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:40:37 by kboulkri          #+#    #+#             */
/*   Updated: 2024/11/11 21:30:11 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{

    Bureaucrat director;
    Bureaucrat supervisor;
    Bureaucrat cashier;
    Bureaucrat CEO;

    director.setGrade(150);
    supervisor.setGrade(100);
    cashier.setGrade(0);

    std::cout << "----- Trying to set CEO above 150 -----" << std::endl << std::endl;
    try
    {
        CEO.setGrade(200);
    }
    catch(std::string const& error)
    {
        std::cout << error << std::endl;
    }
    std::cout << std::endl << "----- Trying to ++ Director -----" << std::endl;
    try
    {
        director.AddGrade();
    }
    catch(std::string const& error)
    {
        std::cout << error << std::endl;
    }
    std::cout << std::endl << "----- Trying to -- Cashier -----" << std::endl;
    try
    {
        cashier.MinGrade();
    }
    catch(std::string const& error)
    {
        std::cout << error << std::endl;
    }
    std::cout << std::endl;
    std::cout << "----- Print Grade via opertaor << -----" << std::endl << std::endl;
    std::cout << director.getName() << "bureaucrat grade : " << director.getGrade() << std::endl;
    std::cout << cashier.getName() << "cashier grade : " << cashier.getGrade() << std::endl; 
    std::cout << supervisor.getName() << "supervisor grade : " << supervisor.getGrade() << std::endl; 
}