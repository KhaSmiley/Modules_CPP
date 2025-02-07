#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <stdio.h>
#include <stdlib.h>

class PhoneBook
{
    public :
        PhoneBook(void);
        ~PhoneBook(void);
        int i;
        void ft_search(void);
        void ft_add(void);

    private :
        Contact Contacts[8];
        void display_contact_list(int i);
        void display_contact_header(void);
        void ft_show_contact(std::string);
        int register_first_name(void);
        int register_last_name(void);
        int register_nickname(void);
        int register_phone_number(void);
        int register_darkest_secret(void);
        int check_darkest_secret(std::string);
        int check_str_alpha(std::string);
        int check_str_digit(std::string);
        std::string check_len(std::string);

};

#endif