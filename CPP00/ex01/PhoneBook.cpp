#include "PhoneBook.hpp"

// MAIN FUNCTIONS //

PhoneBook::PhoneBook(void)
{
    std::cout << "WELCOME TO YOUR CONTACT LIST" << std::endl;
}

PhoneBook::~PhoneBook(void)
{
    std::cout << "PhoneBook has been destroyed" << std::endl;
}

void PhoneBook::ft_show_contact(std::string index)
{
    int i = atoi(index.c_str());
    if (i > 0 && i < 9)
    {
        std::cout << "First Name: " << this->Contacts[i - 1].get_first_name() << std::endl;
        std::cout << "Last Name: " << this->Contacts[i - 1].get_last_name() << std::endl;
        std::cout << "Nickname: " << this->Contacts[i - 1].get_nickname() << std::endl;
        std::cout << "Phone Number: " << this->Contacts[i - 1].get_phone_number() << std::endl;
        std::cout << "Darkest Secret: " << this->Contacts[i - 1].get_darkest_secret() << std::endl;
    }
    else
        std::cout << "Please enter a valid index" << std::endl;
}

void PhoneBook::ft_search(void)
{
    int i;
    std::string input;
    PhoneBook::display_contact_header();
    for (i = 0; i < 8; i++){
        PhoneBook::display_contact_list(i);
    }
    std::cout << "Please enter the index of the contact you want to see" << std::endl;
    while (!std::cin.eof())
    {
        getline(std::cin, input);
        if ((input.length() > 1 || !isdigit(input[0]) || input.empty()) && !std::cin.eof())
            std::cout << "Please enter a valid index" << std::endl;
        else
            break ;
    }
    if (!std::cin.eof())
        ft_show_contact(input);
    return ;
}

void PhoneBook::ft_add(void)
{
    if (PhoneBook::i >= 8)
        PhoneBook::i = 0;
    if (PhoneBook::register_first_name() == 1)
        return ;
    if (PhoneBook::register_last_name() == 1)
        return ;
    if (PhoneBook::register_nickname() == 1)
        return ;
    if (PhoneBook::register_phone_number() == 1)
        return ;
    if (PhoneBook::register_darkest_secret() == 1)
        return ;
    PhoneBook::i = i + 1;
    std::cout << "Contact has been added" << std::endl;
}


// REGISTER FUNCTIONS //

int PhoneBook::register_first_name(void)
{
    std::string input;
    std::cout << "Please add a first name" << std::endl;
    while(!std::cin.eof())
    {
        getline(std::cin, input);
        if ((check_str_alpha(input) == 1 || input.empty()) && !std::cin.eof())
            std::cout << "Please enter a valid first name" << std::endl;
        else
            break ;
    }
    if (!std::cin.eof())
    {
        this->Contacts[this->i].set_first_name(input);
        return (0);
    }
    return (1);
}

int PhoneBook::register_last_name(void)
{
    std::string input;
    std::cout << "Please add a last name" << std::endl;
    while(!std::cin.eof())
    {
        getline(std::cin, input);
        if ((check_str_alpha(input) == 1 || input.empty()) && !std::cin.eof())
            std::cout << "Please enter a valid last name" << std::endl;
        else
            break ;
    }
    if (!std::cin.eof())
    {
        this->Contacts[this->i].set_last_name(input);
        return (0);
    }
    return (1);
}

int PhoneBook::register_nickname(void)
{
    std::string input;
    std::cout << "Please add a nickname" << std::endl;
    while(!std::cin.eof())
    {
        getline(std::cin, input);
        if ((check_str_alpha(input) == 1 || input.empty()) && !std::cin.eof())
            std::cout << "Please enter a valid nickname" << std::endl;
        else
            break ;
    }
    if (!std::cin.eof())
    {
        this->Contacts[this->i].set_nickname(input);
        return (0);
    }
    return (1);
}

int PhoneBook::register_phone_number(void)
{
    std::string input;
    std::cout << "Please add a phone number" << std::endl;
    while(!std::cin.eof())
    {
        getline(std::cin, input);
        if ((check_str_digit(input) == 1 || input.length() > 10 || input.empty()) && !std::cin.eof())
            std::cout << "Please enter a valid phone number" << std::endl;
        else
            break ;
    }
    if (!std::cin.eof())
    {
        this->Contacts[this->i].set_phone_number(input);
        return (0);
    }
    return (1);
}

int PhoneBook::register_darkest_secret(void)
{
    std::string input;
    std::cout << "Please enter the darkest secret" << std::endl;
    while(!std::cin.eof())
    {
        getline(std::cin, input);
        if ((check_darkest_secret(input) == 1 || input.empty()) && !std::cin.eof()) // ou espaces
            std::cout << "Please enter a valid darkest secret" << std::endl;
        else
            break ;
    }
    if (!std::cin.eof())
    {
        this->Contacts[this->i].set_darkest_secret(input);
        return (0);
    }
    return (1);
}


// DISPLAY FUNCTIONS //


void PhoneBook::display_contact_header(void)
{
    std::cout << " ___________________________________________" << std::endl;
    std::cout << "|     Index|First Name| Last Name|  Nickname| " << std::endl;
    std::cout << " ___________________________________________ " << std::endl;
}

void PhoneBook::display_contact_list(int i)
{
    std::cout << "|";
    std::cout << std::setw(10) << i + 1 << std::right << "|";
    std::cout << std::setw(10) << PhoneBook::check_len(this->Contacts[i].get_first_name()) << std::right << "|";
    std::cout << std::setw(10) << PhoneBook::check_len(this->Contacts[i].get_last_name()) << std::right << "|";
    std::cout << std::setw(10) << PhoneBook::check_len(this->Contacts[i].get_nickname()) << std::right << "|";
    std::cout << std::endl;
}
// PARSING FUNCTIONS //

int PhoneBook::check_darkest_secret(std::string str)
{
    if (str.empty())
        return (1);
    for(size_t i = 0; str[i]; i++)
    {
        if (!isalpha(str[i]) && !isalnum(str[i]) && str[i] != ' ')
            return (1);
    }
    return (0);
}

int PhoneBook::check_str_alpha(std::string str)
{
    if (str.empty())
        return (1);
    for(size_t i = 0; str[i]; i++)
    {
        if (!isalpha(str[i]))
            return (1);
    }
    return (0);
}

int PhoneBook::check_str_digit(std::string str)
{
    for(size_t i = 0; i < str.length(); i++)
    {
        if (!isdigit(str[i]))
            return (1);
    }
    return (0);
}

std::string PhoneBook::check_len(std::string str)
{
    if (str.length() > 9)
        return (str.substr(0, 9) + ".");
    return (str);
}