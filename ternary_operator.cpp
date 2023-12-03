#include <iostream>

int main()
{
    int x, y;
    x = 5;
    y = 7;

    // if-else statement:
    if (y > x)
    {
        std::cout << "If-else: Y is greater than X!\n";
    }
    else
    {
        std::cout << "If-else: X is greater than Y!\n";
    }

    // ternary operator: (Condition ? Expression1 : expression2;)

    y > x ? std::cout << "Ternary: Y is greater than X!\n" : std::cout << "Ternary: X is greater than Y!\n";

    return 0;
}