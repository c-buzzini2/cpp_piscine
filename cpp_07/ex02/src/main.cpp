#include "Array.hpp"

int main (void)
{
    Array<int> a;
    Array<int> b(5);

    for (int i = 0; i < 5; i++)
        std::cout << b[i] << std::endl;

    for (int i = 0; i < 5; i++)
    {
        b[i] = i + 3;
        std::cout << b[i] << std::endl;
    }

    Array<const char*> c(2);
    
    c[0] = "Hello";
    c[1] = "World";

    for (int i = 0; i < 2; i++)
        std::cout << c[i] << std::endl;

    try
    {
        std::cout << b[5];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

}