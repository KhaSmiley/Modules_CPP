#include "PhoneBook.hpp"
#include "Contact.hpp"

#include <iomanip>
#include <iostream>
#include <sstream>

int main(void)
{
    PhoneBook iPhoneBook;
    std::string string;

    iPhoneBook.i = 0;
    while (1 && !std::cin.eof())
    {
        getline(std::cin, string);
        if (string == "ADD")
            iPhoneBook.ft_add();
        if (string == "SEARCH")
            iPhoneBook.ft_search();
        if (string == "EXIT")
            break ;
    }
    return (0);
}