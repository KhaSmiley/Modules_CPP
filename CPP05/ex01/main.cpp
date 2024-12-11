/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 23:22:36 by kboulkri          #+#    #+#             */
/*   Updated: 2024/12/11 01:46:12 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

// const std::string name;
// bool  is_signed;
// const int grade_min_sign;
// const int grade_min_exec;

// const std::string name;
//     int grade;

int main ( void )
{
    Bureaucrat Cashier ("Cashier", 150);
    Bureaucrat CEO ("Elon", 10);
	Form Cashier_contract ("Cashier's Contract", 150, 150);
    Form CEO_contract ("CEO's Contract", 1, 1);
    
    std::cout << std::endl << Cashier_contract << std::endl;
    try
    {
        CEO.signForm(Cashier_contract);
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what();
    }
    try
    {
        Cashier.signForm(CEO_contract);
        std::cout << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what();
    }
	return (0);
}