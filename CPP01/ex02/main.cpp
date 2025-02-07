/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:16:08 by kboulkri          #+#    #+#             */
/*   Updated: 2024/10/29 19:34:19 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::string string = "HI THIS IS BRAIN";
    std::string *stringPTR = &string;
    std::string &stringREF = string;

    std::cout << "String address in memory : " << &string << std::endl;
    std::cout << "StringPTR address : " << stringPTR << std::endl;
    std::cout << "StringREF address : " << &stringREF << std::endl;
    
    std::cout << std::endl;
    
    std::cout << "String value : " << string << std::endl;
    std::cout << "StringPTR value : " << *stringPTR << std::endl;
    std::cout << "StringREF value : " << stringREF << std::endl;

    return (0);
}