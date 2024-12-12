/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 03:29:58 by kboulkri          #+#    #+#             */
/*   Updated: 2024/12/12 03:07:37 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ShrubberyCreationForm.cpp

// ShrubberyCreationForm: Required grades: sign 145, exec 137
// Create a file <target>_shrubbery in the working directory, and writes ASCII trees inside it.

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default_target"), _gradeSign(145)
{
    std::cout << "Shrubbery :: Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target + "_Shrubbery"), _gradeSign(145)
{
    std::cout << "Shrubbery :: Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
{
    std::cout << "Shrubbery :: Copy constructor called" << std::endl;
    *this = other;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) 
{
    std::cout << "Shrubbery :: Copy assignment operator called" << std::endl;
    this->_target = other._target;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "Shrubbery :: Destructor called" << std::endl;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->get_is_signed() == false)
		throw FormNotSignedException();
	if (executor.getGrade() > this->_gradeSign)
		throw GradeTooLowException();
	std::string fileName = this->_target + "_shrubbery";
	std::ofstream file(fileName.c_str());
	if (file.is_open())
	{
        file << "                                                                 " << std::endl;
        file << "                                              .         ;        " << std::endl;
        file << "                 .              .              ;%     ;;         " << std::endl;
        file << "                   ,           ,                :;%  %;          " << std::endl;
        file << "                    :         ;                   :;%;'     .,   " << std::endl;
        file << "           ,.        %;     %;            ;        %;'    ,;     " << std::endl;
        file << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'      " << std::endl;
        file << "              %;       %;%;      ,  ;       %;  ;%;   ,%;'       " << std::endl;
        file << "               ;%;      %;        ;%;        % ;%;  ,%;'         " << std::endl;
        file << "                `%;.     ;%;     %;'         `;%%;.%;'           " << std::endl;
        file << "                 `:;%.    ;%%. %@;        %; ;@%;%'              " << std::endl;
        file << "                    `:%;.  :;bd%;          %;@%;'                " << std::endl;
        file << "                      `@%:.  :;%.         ;@@%;'                 " << std::endl;
        file << "                        `@%.  `;@%.      ;@@%;                   " << std::endl;
        file << "                          `@%%. `@%%    ;@@%;                    " << std::endl;
        file << "                            ;@%. :@%%  %@@%;                     " << std::endl;
        file << "                              %@bd%%%bd%%:;                      " << std::endl;
        file << "                                #@%%%%%:;;                       " << std::endl;
        file << "                                %@@%%%::;                        " << std::endl;
        file << "                                %@@@%(o);  . '                   " << std::endl;
        file << "                                %@@@o%;:(.,'                     " << std::endl;
        file << "                            `.. %@@@o%::;                        " << std::endl;
        file << "                               `)@@@o%::;                        " << std::endl;
        file << "                                %@@(o)::;                        " << std::endl;
        file << "                               .%@@@@%::;                        " << std::endl;
        file << "                               ;%@@@@%::;.                       " << std::endl;
        file << "                              ;%@@@@%%:;;;.                      " << std::endl;
        file << "                          ...;%@@@@@%%:;;;;,..                   " << std::endl;
    }
    else
	    std::cout << "Check out the file: " << fileName << "!" << std::endl;
    file.close();
}