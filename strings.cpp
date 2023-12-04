#include <string>
#include <iostream>

int main()
{
    std::string string ("Das ist ein String!");



    for (int i = 0; i < string.size(); i++)
    {
        std::cout << string[i];
    }

    return 0;
}