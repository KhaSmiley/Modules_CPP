/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:40:37 by kboulkri          #+#    #+#             */
/*   Updated: 2024/12/02 20:45:23 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{

    Bureaucrat CEO("CEO", 0);
    Bureaucrat director("Director", 0);
    Bureaucrat supervisor("Supervisor", 50);
    Bureaucrat cashier("Cashier", 150);

    std::cout << std::endl << "----- Trying to set CEO under 0 -----" << std::endl << std::endl;
    try
    {
        CEO.setGrade(-1);
    }
    catch(std::exception const& error)
    {
        std::cout << error.what() << std::endl;
    }
    std::cout << "----- Trying to AddGrade Director -----" << std::endl << std::endl;;
    try
    {
        director.AddGrade();
    }
    catch(std::exception const& error)
    {
        std::cout << error.what() << std::endl;
    }
    std::cout << "----- Trying to MinGrade Cashier -----" << std::endl << std::endl;;
    try
    {
        cashier.MinGrade();
    }
    catch(std::exception const& error)
    {
        std::cout << error.what() << std::endl;
    }
    std::cout << "----- Print Grade via operator << -----" << std::endl << std::endl;
    std::cout << director.getName() << " Director's grade : " << director.getGrade() << std::endl;
    std::cout << supervisor.getName() << " Supervisor's grade : " << supervisor.getGrade() << std::endl;
    std::cout << cashier.getName() << " Cashier's grade : " << cashier.getGrade() << std::endl << std::endl; 
    try
    {
        CEO.setGrade(0);
        director.setGrade(25);
        cashier.AddGrade();
        director.AddGrade();
        supervisor.AddGrade();
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    std::cout << CEO.getName() << "'s grade : " << CEO.getGrade() << std::endl;
    std::cout << director.getName() << "'s grade : " << director.getGrade() << std::endl;
    std::cout << supervisor.getName() << "'s grade : " << supervisor.getGrade() << std::endl;
    std::cout << cashier.getName() << "'s grade : " << cashier.getGrade() << std::endl << std::endl; 
}