/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 02:12:21 by kboulkri          #+#    #+#             */
/*   Updated: 2024/12/12 23:26:46 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

int main()
{
	std::cout << "--- Creation of Form and Bureaucrat that works ---" << std::endl << std::endl;
    try
	{
		AForm *form1 = new RobotomyRequestForm("Robot");
		AForm *form2 = new PresidentialPardonForm("Presidential");
		AForm *form3 = new ShrubberyCreationForm("Shrubbery");
		Bureaucrat *bureaucrat = new Bureaucrat("Bureaucrat", 1);

		std::cout << std::endl;
		form1->beSigned(*bureaucrat);
		form1->execute(*bureaucrat);
		std::cout << std::endl;
		form2->beSigned(*bureaucrat);
		form2->execute(*bureaucrat);
		std::cout << std::endl;
		form3->beSigned(*bureaucrat);
		form3->execute(*bureaucrat);
		std::cout << std::endl;
		delete form1;
		delete form2;
		delete form3;
		delete bureaucrat;
		std::cout << std::endl;

	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "--- Creation of Form and Bureaucrat that can't sign ---" << std::endl;
	Bureaucrat *Cashier = new Bureaucrat("Cashier", 150);
	AForm *form1 = new PresidentialPardonForm("Robot");
	try
	{

		std::cout << std::endl;
		form1->beSigned(*Cashier);
		form1->execute(*Cashier);
		std::cout << std::endl;
		delete Cashier;
		delete form1;
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		delete Cashier;
		delete form1;
		std::cout << std::endl;
	}
	std::cout << "--- Creation of Form and Bureaucrat that can't execute ---" << std::endl << std::endl;
	try
	{
		Bureaucrat *Cashier = new Bureaucrat("Cashier", 71);
		AForm *form1 = new RobotomyRequestForm("Robot");

		std::cout << std::endl;
		form1->beSigned(*Cashier);
		form1->execute(*Cashier);
		std::cout << std::endl;
		delete Cashier;
		delete form1;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}