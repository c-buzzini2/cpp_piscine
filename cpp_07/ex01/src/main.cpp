#include "iter.hpp"


int main (void)
{
    int a[] = {0, 1, 2, 3};

    iter(a, 4, print<int>);
    iter(a, 4, add_A<int>);
    iter(a, 4, print<int>);

    std::string b[] = {"Hello", "awesome", "World"};

    iter(b, 3, print<std::string>);
    iter(b, 3, add_A< std::string>);
    iter(b, 3, print<std::string>);

    return (0);
}