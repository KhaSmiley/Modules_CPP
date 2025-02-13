#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        try
        {
            RPN Casio(av[1]);
            Casio.parse_input();
            Casio.calculate();
            std::cout << "Result = " << Casio.getResult() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what();
        }
    }
    return 0;
}