/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 02:12:21 by kboulkri          #+#    #+#             */
/*   Updated: 2024/12/18 22:49:34 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "Bureaucrat.hpp"
// #include "AForm.hpp"
// # include "ShrubberyCreationForm.hpp"
// # include "RobotomyRequestForm.hpp"
// # include "PresidentialPardonForm.hpp"

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int	main()
{
	Bureaucrat	yes("Bryan", 20);
	Intern	someRandomIntern;

	std::cout << "----- Trying to create a form with the intern -----" << std::endl;
	try
	{
		AForm*	randomForm = someRandomIntern.MakeForm("robotomy request", "uwu");
		yes.signAForm(*randomForm);
		yes.executeForm(*randomForm);
		delete randomForm;	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl << "----- Trying to create a form that doesn't exist with the intern -----" << std::endl << std::endl;
	try
	{
		AForm*	randomForm2 = someRandomIntern.MakeForm("robotomyddddd request", "jean");
		delete randomForm2;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}