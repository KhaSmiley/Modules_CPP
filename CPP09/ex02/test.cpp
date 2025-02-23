#include <vector>
#include <utility>
#include <iostream>

int main()
{
    for(int i = 0; i < 5; i++)
    {
        std::cout << "First for" << std::endl;
        for(int i = 0; i < 5; i++)
        {
            std::cout << "Second for" << std::endl;
        }
    }
}