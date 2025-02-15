#include <iostream>
#include <string>

int main()
{
    std::string oui = "Bonjour je suis la 234sd";

    std::cout << atoi(oui.substr(19).c_str()) << std::endl;
}