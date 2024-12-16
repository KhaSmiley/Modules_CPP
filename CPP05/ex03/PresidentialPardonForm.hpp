/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 03:28:59 by kboulkri          #+#    #+#             */
/*   Updated: 2024/12/12 02:14:52 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// PresidentialPardonForm.hpp
#ifndef PresidentialPardonForm_HPP
#define PresidentialPardonForm_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string const &target);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
        ~PresidentialPardonForm();

		virtual void execute (Bureaucrat const & executor ) const;

        void setTarget(std::string target);
        std::string getTarget() const;

    private:
        std::string _target;
        int _gradeSign;
};

#endif // PresidentialPardonForm_HPP